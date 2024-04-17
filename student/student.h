#include <ros/ros.h>
#include <boost/bind.hpp>
#include <csrtle/timeInt8.h>
#include <std_msgs/Empty.h>
#include <csrtle/RTIbump.h>
#include <csrtle/RTIatend.h>
#include <csrtle/PoseOrntBundle.h>
#include <csrtle/bumpEcho.h>
#include <csrtle/aendEcho.h>
#include <QPointF>

// Functions to interface with ROS. Don't change these lines!
bool bumped(int x1,int y1,int x2,int y2);
bool atend(int x, int y);
void displayVisits(int visits);
bool moveTurtle(QPointF& pos_, int& nw_or);

// Scope-preserving changes to these lines permitted (see p5 writeup)
enum turtleMove {MOVE};
QPointF translatePos(QPointF pos_, turtleMove nextMove);
int translateOrnt(int orientation, turtleMove nextMove);
turtleMove studentTurtleStep(bool bumped);

// OK to change below this line
bool studentMoveTurtle(QPointF& pos_, int& nw_or);


