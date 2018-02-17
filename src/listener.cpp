#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

using namespace std;

ros::Publisher name_pub;
ros::Publisher age_pub;
ros::Publisher height_pub;
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  std_msgs::String name;
  std_msgs::String age;
  std_msgs::String height;

  //std_msgs::Int32 count1;
  //std_msgs::Int32 count2;

int count1;
int count2;
int len;
int flag =0;

  std::string line;

  //cout << msg->data <<endl;
/*
  line = msg->data.substr(3,5);
  cout << line << endl;
*/

  for(int i =0; i < (msg->data).length(); i++){
	if (msg->data[i] == ':'){
		count1 = i+2;
		}
        if (msg->data[i] == ','){
		count2 = i;
		len = count2 - count1;
		
		if (flag == 0){
		name = msg->data.substr(count1,len);	
		cout << "name =" << name << "\n";
		flag = flag+1;

		}

		else if (flag ==1){
		age = msg->data.substr(count1, len);
		cout <<"age =" << age << "\n";
		flag = flag+1;

		}

		else if (flag ==2){
		height = msg->data.substr(count1, len);
		cout << "height =" << height << "\n";
		flag = 0;

		}
}

}

  //struct student;

  //std::vector<std::struct> students;
  //std::string line; 
  
  //while(std::getline(std::cin, line))

/*
  while(std::getline(msg->data.c_str(), line))
  {
     std::istringstream ss(line);
     std::istream_iterator<std::string> begin(ss), end;
     std::vector<std::string> words(begin, end);

     assert(words.size() >= 3);

     int n = words.size() -1;
     student s {words[0], words[n-1], words[n] };
     for (int i = 1; i < n - 3; i++) s.name += " " + words[i];

     students.push_back(s);
}
*/

//printitng 
/*
for(auto && s : students)
	std::cout << "name      =" << s.name << "\n"
                  << "age     =" << s.age << "\n"
		  << "height  =" << s.height << "\n";

*/

  //ROS_INFO("I heard: [%s]", msg->data.c_str());  
}

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "listener");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  name_pub = n.advertise<std_msgs::String>("name", 1000); //añadir 3 de estos
  age_pub = n.advertise<std_msgs::Int

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}
