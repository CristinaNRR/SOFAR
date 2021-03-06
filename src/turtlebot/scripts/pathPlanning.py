#!/usr/bin/env python

"""
    ar_follower.py - Version 1.0 2013-08-25
    
    Follow an AR tag published on the /ar_pose_marker topic.  The /ar_pose_marker topic
    is published by the ar_track_alvar package
    
    Created for the Pi Robot Project: http://www.pirobot.org
    Copyright (c) 2013 Patrick Goebel.  All rights reserved.
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details at:
    
    http://www.gnu.org/licenses/gpl.html
"""

import rospy
from std_msgs.msg import Bool
from std_msgs.msg import String
from std_msgs.msg import Int32
from ar_track_alvar_msgs.msg import AlvarMarkers
from geometry_msgs.msg import Twist
from math import copysign

class ARFollower():
    def __init__(self):
        rospy.init_node("pathPlanning")
                        
        # Set the shutdown function (stop the robot)
        rospy.on_shutdown(self.shutdown)
        
        # How often should we update the robot's motion?
        self.rate = rospy.get_param("~rate", 10)
        r = rospy.Rate(self.rate) 
        
        # The maximum rotation speed in radians per second
        self.max_angular_speed = rospy.get_param("~max_angular_speed", 2.0)
        
        # The minimum rotation speed in radians per second
        self.min_angular_speed = rospy.get_param("~min_angular_speed", 0.5)
        
        # The maximum distance a target can be from the robot for us to track
        self.max_x = rospy.get_param("~max_x", 20.0)
        
        # The goal distance (in meters) to keep between the robot and the marker
        self.goal_x = rospy.get_param("~goal_x", 0.6)
        
        # How far away from the goal distance (in meters) before the robot reacts
        self.x_threshold = rospy.get_param("~x_threshold", 0.05)
        
        # How far away from being centered (y displacement) on the AR marker
        # before the robot reacts (units are meters)
        self.y_threshold = rospy.get_param("~y_threshold", 0.05)
        
        # How much do we weight the goal distance (x) when making a movement
        self.x_scale = rospy.get_param("~x_scale", 0.5)

        # How much do we weight y-displacement when making a movement        
        self.y_scale = rospy.get_param("~y_scale", 1.0)
        
        # The max linear speed in meters per second
        self.max_linear_speed = rospy.get_param("~max_linear_speed", 0.3)
        
        # The minimum linear speed in meters per second
        self.min_linear_speed = rospy.get_param("~min_linear_speed", 0.1)

        # Publisher to control the robot's movement
        self.cmd_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size=5)
        
        # Intialize the movement command
        self.move_cmd = Twist()
        #define 3 flags
	self.flag_rot=False
	self.flag_room=False
	self.flag_marker=False
	self.count = 0
        
        # Set flag to indicate when the AR marker is visible
        self.target_visible = False
	#subscribe to know when robot finish rotating
	rospy.Subscriber('finish_rotating', Bool, self.rotation)
        #subscribe to topic parla to have the goal room
        rospy.Subscriber('topicPathPlanner_IdGoal', Int32, self.get_room_id)
	#publish to go_to_room topic of "motion" node the id of the goal room
	motion_pub = rospy.Publisher('go_to_room', String, queue_size=10)
	#publish to x topic of GUI node the id of the current room
	GUI_pub = rospy.Publisher('topicPathPlanner_IdNow', Int32, queue_size=10)
        # Wait for the ar_pose_marker topic to become available
        rospy.loginfo("Waiting for ar_pose_marker topic...")
        rospy.wait_for_message('ar_pose_marker', AlvarMarkers)
        rospy.loginfo('1')
        # Subscribe to the ar_pose_marker topic to get the image width and height
        rospy.Subscriber('ar_pose_marker', AlvarMarkers, self.set_cmd_vel)
        rospy.loginfo('3')
        rospy.loginfo("Marker messages detected. Starting follower...")
        
        # controllo se tutti e 3 i flag sono true, se no non faccio nulla
        while not rospy.is_shutdown():
	    if(self.flag_marker==True):
			if(self.id_marker=='0'):
				rospy.loginfo('you are in room 3')
			else:
				rospy.loginfo('you are in room: %s', self.id_marker)
			self.marker2=int(self.id_marker)
			GUI_pub.publish(self.marker2)
	    if (self.flag_marker==True and self.flag_rot==True and self.flag_room==True):
		if (self.count == 1):
			self.flag_marker=False
			self.flag_room=False
		self.count = self.count + 1
                if(self.room_id == self.id_marker):
			rospy.loginfo('you are in the goal room!')
			self.flag_marker=True
			self.count=0
			
		else:
			#activate the goToSpecificPoint node
			msg = self.room_id
			motion_pub.publish(msg)

			if(self.room_id=='0'):
				rospy.loginfo('moving the robot to room: 3')
			else:
				rospy.loginfo('moving the robot to room: %s', self.room_id)

       
            
            # Sleep for 1/self.rate seconds
            r.sleep()

    def rotation(self, data):
	self.flag_rot = data.data



    def get_room_id (self, data):
    	self.room= data.data
	self.room_id=str(self.room)
	self.flag_room=True



    def set_cmd_vel(self, msg):

	#if the marker is detected
        try:
            marker = msg.markers[0]
            if not self.target_visible:
                rospy.loginfo("Marker detected")
		self.count=0
                #global flag_marker 
		self.flag_marker= True
            self.target_visible = True
        except:
            
            self.target_visible = False
            
            return
                
      
	#save id of the detected marker
	self.id_marker = str(marker.id)
        
     
      

    def shutdown(self):
        rospy.loginfo("Stopping the robot...")
        self.cmd_vel_pub.publish(Twist())
        rospy.sleep(1)     

if __name__ == '__main__':
    try:
        ARFollower()
        rospy.spin()
    except rospy.ROSInterruptException:
        rospy.loginfo("AR follower node terminated.")
