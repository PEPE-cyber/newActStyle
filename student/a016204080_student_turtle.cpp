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
enum Orientation {
	kNorth = 0,
	kEast = 1,
	kSouth = 2,
	kWest = 3
};

// OK TO MODIFY BELOW THIS LINE

#define TIMEOUT 40 // bigger number slows down simulation so you can see what's happening
float w, cs;
float fx1, fy1, fx2, fy2;
float z, aend, mod, bp, q;

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
		fx1 = current_position.x();
		fy1 = current_position.y();
		fx2 = current_position.x();
		fy2 = current_position.y();
		if (new_orientation < 2)
			if (new_orientation == 0)
				fy2 += 1;
			else
				fx2 += 1;
		else
		{
			fx2 += 1;
			fy2 += 1;
			if (new_orientation == 2)
				fx1 += 1;
			else
				fy1 += 1;
		}
		bp = bumped(fx1, fy1, fx2, fy2);
		aend = atend(current_position.x(), current_position.y());
		if (new_orientation == 0)
			if (cs == 2)
			{
				new_orientation = 3;
				cs = 1;
			}
			else if (bp)
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
			else if (bp)
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
			else if (bp)
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
			else if (bp)
			{
				new_orientation = 0;
				cs = 0;
			}
			else
				cs = 2;
		ROS_INFO("Orientation=%f  STATE=%f", new_orientation, cs);
		z = cs == 2;
		mod = true;
		if (z == true && aend == false)
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
	if (aend)
		return false;
	if (w == 0)
		w = TIMEOUT;
	else
		w -= 1;
	if (w == TIMEOUT)
		return true;
	return false;
}
