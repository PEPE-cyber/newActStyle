/*
 * Originally by Philip Koopman (koopman@cmu.edu)
 * and Milda Zizyte (milda@cmu.edu)
 *
 * STUDENT NAME:
 * ANDREW ID:
 * LAST UPDATE:
 *
 * This file is an algorithm to solve the csrtle maze
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

}

// OK TO MODIFY BELOW THIS LINE

#define TIMEOUT 40 // bigger number slows down simulation so you can see what's happening
float w,
	cs;
float current_x, current_y, next_x, next_y;
float z, is_at_end, mod, is_bumped, q;

// this procedure takes the current turtle position and orientation and returns
// true=submit changes, false=do not submit changes
// Ground rule -- you are only allowed to call the helper functions "bumped(..)" and "atend(..)",
// and NO other turtle methods or maze methods (no peeking at the maze!)
bool studentMoveTurtle(QPointF &current_position, int &new_orientation)
{
	ROS_INFO("Turtle update Called  w=%f", w);
	mod = true;
	if (w == 0)
	{
		current_x = current_position.x();
		current_y = current_position.y();
		next_x = current_position.x();
		next_y = current_position.y();
		if (new_orientation == kFoward)
			next_y += 1;
		else if (new_orientation == kRight)
			next_x += 1;
		is_bumped = bumped(current_x, current_y, next_x, next_y);
		is_at_end = atend(current_position.x(), current_position.y());
		if (new_orientation == 0)
			if (cs == 2)
			{
				new_orientation = 3;
				cs = 1;
			}
			else if (is_bumped)
			{
				new_orientation = 1;
				cs = 0;
			}
			else
				cs = 2;
		else if (new_orientation == 1)
			if (cs == 2)
			{
				new_orientation = 0;
				cs = 1;
			}
			else if (is_bumped)
			{
				new_orientation = 2;
				cs = 0;
			}
			else
				cs = 2;
		else if (new_orientation == 2)
			if (cs == 2)
			{
				new_orientation = 1;
				cs = 1;
			}
			else if (is_bumped)
			{
				new_orientation = 3;
				cs = 0;
			}
			else
				cs = 2;
		else if (new_orientation == 3)
			if (cs == 2)
			{
				new_orientation = 2;
				cs = 1;
			}
			else if (is_bumped)
			{
				new_orientation = 0;
				cs = 0;
			}
			else
				cs = 2;
		ROS_INFO("Orientation=%f  STATE=%f", new_orientation, cs);
		z = cs == 2;
		mod = true;
		if (z == true && is_at_end == false)
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
			mod = true;
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
