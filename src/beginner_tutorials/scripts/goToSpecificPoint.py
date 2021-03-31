#!/usr/bin/env python

'''
Copyright (c) 2015, Mark Silliman
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
'''

# TurtleBot must have minimal.launch & amcl_demo.launch
# running prior to starting this script
# For simulation: launch gazebo world & amcl_demo prior to run this script

import rospy
from std_msgs.msg import String
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
import actionlib
from actionlib_msgs.msg import *
from geometry_msgs.msg import Pose, Point, Quaternion
from ar_track_alvar_msgs.msg import AlvarMarkers

class GoToPose():
    def __init__(self):
	#subscribe to ar track and when it detects a marker i save the marker id
	#rospy.Subscriber('parla', String, self.callback)
	#rospy.Subscriber('ar_pose_marker', AlvarMarkers, self.set_cmd_vel)
	self.goal_sent = False

	# What to do if shut down (e.g. Ctrl-C or failure)
	rospy.on_shutdown(self.shutdown)
	
	# Tell the action client that we want to spin a thread by default
	self.move_base = actionlib.SimpleActionClient("move_base", MoveBaseAction)
	rospy.loginfo("Wait for the action server to come up")

	# Allow up to 5 seconds for the action server to come up
	self.move_base.wait_for_server(rospy.Duration(5))
        rospy.Subscriber('go_to_room', String, self.callback)
	while(1):
		pass






    def callback(self,data):
     	
	room_id = data.data
	#navigator = self.callback2()
        # Customize the following values so they are appropriate for your location
	if(room_id == '2'):
        	position = {'x': 3.12, 'y' : -3.92}
        	quaternion = {'r1' : 0.000, 'r2' : 0.000, 'r3' : 0.000, 'r4' : 1.000}
	elif(room_id=='0'):
        	position = {'x': -1.28, 'y' : 0.934}
        	quaternion = {'r1' : 0.000, 'r2' : 0.000, 'r3' : 0.000, 'r4' : 1.000}	
	elif(room_id=='1'):
        	position = {'x': -3.84, 'y' : -4.19}
        	quaternion = {'r1' : 0.000, 'r2' : 0.000, 'r3' : 0.000, 'r4' : 1.000}		

        rospy.loginfo("Go to (%s, %s) pose", position['x'], position['y'])
       # success = navigator.goto(position, quaternion)
	success = self.goto(position, quaternion)

	#if (self.id_marker==self.room_id):
	#	rospy.loginfo("we reached the goal room!")
			
    #    if success:
     #       rospy.loginfo("We reached the desired pose")
	   # if (self.id_marker == self.room_id):
		#rospy.loginfo("great")
	   
#        else:
 #           rospy.loginfo("The base failed to reach the desired pose")

        # Sleep to give the last log messages time to be sent
        #rospy.sleep(1)
	

  #  def set_cmd_vel(self, msg):
        # Pick off the first marker (in case there is more than one)
	#rospy.loginfo('2')
   #     try:
    #        marker = msg.markers[0]
	   # rospy.loginfo('2.1')
	  #  flag_marker = True
           #save id of the detected marker
     #       self.id_marker = marker.id
     #   except:
	   # rospy.loginfo('2.2')
            
      #      return
                
 

    def goto(self, pos, quat):

        # Send a goal
        self.goal_sent = True
	goal = MoveBaseGoal()
	goal.target_pose.header.frame_id = 'map'
	goal.target_pose.header.stamp = rospy.Time.now()
        goal.target_pose.pose = Pose(Point(pos['x'], pos['y'], 0.000),
                                     Quaternion(quat['r1'], quat['r2'], quat['r3'], quat['r4']))

	# Start moving
        self.move_base.send_goal(goal)

	# Allow TurtleBot up to 60 seconds to complete task
	success = self.move_base.wait_for_result(rospy.Duration(60)) 

        state = self.move_base.get_state()
        result = False

        if success and state == GoalStatus.SUCCEEDED:
            # We made it!
            result = True
        else:
            self.move_base.cancel_goal()

        self.goal_sent = False
        return result

    def shutdown(self):
        if self.goal_sent:
            self.move_base.cancel_goal()
        rospy.loginfo("Stop")
        rospy.sleep(1)

if __name__ == '__main__':
    try:
        rospy.init_node('nav_test', anonymous=False)
	#wait for room topic to proceed
	GoToPose()
        rospy.spin()
        #rospy.Subscriber('go_to_room', String, callback)
	#rospy.loginfo("Waiting for room topic...")
        #rospy.wait_for_message('go_to_room', String)
        #subscribe from room topic and get the goal room id
	

    except rospy.ROSInterruptException:
        rospy.loginfo("Ctrl-C caught. Quitting")
