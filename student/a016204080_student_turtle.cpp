/*
 * Originally by Philip Koopman (koopman@cmu.edu)
 * and Milda Zizyte (milda@cmu.edu)
 *
 * STUDENT NAME:
 * ANDREW ID:
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
	kFoward = 0,
	kRight = 1,
	kLeft = 2,
	kBack = 3
};

enum States
{	
	kBlocked = 0,
	kUnkown = 1,
	kReadyToMove = 2,
};

// OK TO MODIFY BELOW THIS LINE

#define TIMEOUT 1 // bigger number slows down simulation so you can see what's happening
float w, state;
float current_x, current_y, next_x, next_y;
float ready_to_move, is_at_end, is_bumped;
// q and mode

// this procedure takes the current turtle position and orientation and returns
// true=submit changes, false=do not submit changes
// Ground rule -- you are only allowed to call the helper functions "bumped(..)" and "atend(..)",
// and NO other turtle methods or maze methods (no peeking at the maze!)
bool studentMoveTurtle(QPointF &current_position, int &new_orientation)
{
	ROS_INFO("Turtle update Called  w=%f", w);
	if (w == 0)
	{
		current_x = current_position.x();
		current_y = current_position.y();
		next_x = current_position.x();
		next_y = current_position.y();
		if (new_orientation == Orientation::kFoward)
			next_y += 1;
		else if (new_orientation == kRight)
			next_x += 1;
		is_bumped = bumped(current_x, current_y, next_x, next_y);
		is_at_end = atend(current_position.x(), current_position.y());
		
		// if it is ready to move, means it is a new cell
		if (state == States::kReadyToMove){
			// set the state to unknown
			state = States::kUnkown;
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
		if (ready_to_move == true && is_at_end == false)
		{
			if (new_orientation == 1)
				current_position.setY(current_position.y() - 1);
			if (new_orientation == 2)
				current_position.setX(current_position.x() + 1);
			if (new_orientation == 3)
				current_position.setY(current_position.y() + 1);
			if (new_orientation == 0)
				current_position.setX(current_position.x() - 1);
			z = false;
		}
	}
	if (is_at_end)
		return false;
	if (w == 0)
		w = TIMEOUT;
	else
		w -= 1;
	if (w == TIMEOUT)
		return true;
	return false;
}
