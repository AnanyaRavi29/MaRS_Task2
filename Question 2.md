The different Node-Node Communications in ROS are:
1.Topics
2.Services 
3.Actions

#A)WITH TOPICS:
It should be used  for continuous data streams,mainly for continuous data flow. Data might be published and subscribed at any time independent of any senders/receivers. It is a many to many connection.  The publisher decides when data is sent.

Applications:

a)Camera feed

b)Sensor Data



#A)WITH SERVICES:

A Service, which is defined by a pair of messages: one for the request and one for the reply. A providing ROS node offers a service under a string name, and a client calls the service by sending the request message and awaiting the reply.
It should be used for remote procedure calls that terminate quickly, e.g. for querying the state of a node or doing a quick calculation.
It is one to one and bidirectional.
Applications:
a)Spawnning simulation

b)Sending data to get a response


#A)WITH ACTIONS:

It should be used for any discrete behavior that moves a robot or that runs for a longer time but provides feedback during execution.
The most important property of actions is that they can be preempted and preemption should always be implemented cleanly by action servers.
Applications:
a)Moving base of a target

b)Performing a laser scan
