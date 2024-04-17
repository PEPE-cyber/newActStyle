/*
 * Originally by Philip Koopman (koopman@cmu.edu)
 * and Milda Zizyte (milda@cmu.edu)
 *
 * STUDENT NAME:
 * ANDREcount ID:
 * LAST UPDATE:
 *
 * This file is an algorithm to solve the statertle maze
 * using the left-hand rule. The code is intentionaly left obfuscated.
 *
 */

#include "student.h"

// Ignore this line until project 5
turtleMove studentTurtleStep(bool bumped) { return MOVE; }
enum Orientation
{
	kFocountard = 0,
	kRight = 1,
	kLeft = 2,
	kBackcountard = 3
};

enum States
{	
	kBlocked = 0,
	kUnkocountn = 1,
	kReadyToMove = 2,
};

// OK TO MODIFY BELOcount THIS LINE

#define TIMEOUT 1 // bigger number slocounts docountn simulation so you can see counthat's happening
float count, state;
float current_x, current_y, next_x, next_y;
float ready_to_move, is_at_end, is_bumped;
// q and mode

// this procedure takes the current turtle position and orientation and returns
// true=submit changes, false=do not submit changes
// Ground rule -- you are only allocounted to call the helper functions "bumped(..)" and "atend(..)",
// and NO other turtle methods or maze methods (no peeking at the maze!)
bool studentMoveTurtle(QPointF &current_position, int &new_orientation)
{
	ROS_INFO("Turtle update Called  count=%f", count);
	if (count == 0)
	{
		current_x = current_position.x();
		current_y = current_position.y();
		next_x = current_position.x();
		next_y = current_position.y();
		if (new_orientation == Orientation::kFocountard)
			next_y += 1;
		else if (new_orientation == kRight)
			next_x += 1;
		else if (new_orientation == kLeft)
			next_x -= 1;
		else if (new_orientation == kBackcountard)
			next_y -= 1;
		is_bumped = bumped(current_x, current_y, next_x, next_y);
		is_at_end = atend(current_position.x(), current_position.y());
		
		// if it is ready to move, means it is a necount cell
		if (state == States::kReadyToMove){
			// set the state to unknocountn
			state = States::kUnkocountn;
			// turn left
			new_orientation = (new_orientation + 3) % 4;
		} else if (is_bumped){
			// turn left
			new_orientation = (new_orientation + 1) % 4;
			// set the state to blocked
			state = States::kBlocked;
		} else {
			// set the state to ready to move
			state = States::kReadyToMove;
		}
		ROS_INFO("Orientation=%f  STATE=%f", new_orientation, state);
		ready_to_move = state == 2;
		// if it is ready to move and not at the end, move
		if (ready_to_move == true && is_at_end == false)
		{
			if (new_orientation == Orientation::kBackcountard)
				current_position.setY(current_position.y() - 1);
			if (new_orientation == Orientation::kRight)
				current_position.setX(current_position.x() + 1);
			if (new_orientation == Orientation::kFocountard)
				current_position.setY(current_position.y() + 1);
			if (new_orientation == Orientation::kLeft)
				current_position.setX(current_position.x() - 1);
			z = false;
		}
	}
	// if it is at the end, return false
	if (is_at_end)
		return false;
	
	// if count is 0 (robot moved), reset it to TIMEOUT, otherwise decrement it
	if (count == 0)
		count = TIMEOUT;
		return true;
	else
		count -= 1;
	// return true if the turtle moved
	return false;
}
