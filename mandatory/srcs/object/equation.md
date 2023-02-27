<Line-Sphere intersection>

Sphere: (P - C) * (P - C) = r^2
	(P: point on the surface of the sphere)
	(C: center of the Sphere)
	(r: radius of the Sphere)

Line: P(t) = o + t * dir
	(P(t): point this line points to)
	(O: origin of line)
	(dir: direction vector of line)
	(t: scalar value of the direction vector)

Combining these two equations yields an equation for t.
The solution of this equation is the case they intersect.

-> a * t^2 + b * t + c = 0
value of each coefficient:
	a = dir * dir
	b = 2 * (dir * (O - C)
	c = CO^2 - r^2

<Line-Plane intersection>

Plane: (P - P0) * n = 0
	(P: point on the plane)
	(P0: known point that exist on a plane)
	(n: normal vector of a plane)

Line: P(t) = o + t * dir
	(P(t): point this line points to)
	(O: origin of line)
	(dir: direction vector of line)
	(t: scalar value of the direction vector)

Combining these two equations yields an equation for t.
The solution of this equation is the case they intersect.

-> t = (P0 - O) * n / (n * dir)
(If there are countless solutions, it means that a line is contained in the plane.)
(If a given ray is contained in a plane, it is considered not hit)

<Line-Disk intersection>

A disk can be thought of as a limited-area plane, given its center and radius.
So intersection check the same as the plane, but further check the distance between the center and the radius.

Disk: (P - C) * n = 0 (|P - C| <= r)
	(P: point on the disk)
	(C: center of the disk)
	(n: normal vector of a disk)
	(r: radius of the disk)

Line: P(t) = o + t * dir
	(P(t): point this line points to)
	(O: origin of line)
	(dir: direction vector of line)
	(t: scalar value of the direction vector)

Combining these two equations yields an equation for t.
The solution of this equation is the case they intersect.

-> t = (C - O) * n / (n * dir) (|P - C| <= r)
(If there are countless solutions, it means that a line is contained in the disk.)
(If a given ray is contained in a disk, it is considered not hit)

<Line-Tube intersection>

Tube: (P - C)^2 - ((P - C) * ^h)) - r^2 = 0
	(P: point on tube)
	(C: point at the center of the bottom disk)
	(^h: unit vector of the cylinder axis)
	(r: radius of the disk)

Line: P(t) = o + t * dir
	(P(t): point this line points to)
	(O: origin of line)
	(dir: direction vector of line)
	(t: scalar value of the direction vector)

Combining these two equations yields an equation for t.
The solution of this equation is the case they intersect.

-> at^2 + bt + c = 0
value of each coefficient:
	a = (dir)^2 - (dir - ^h)^2
	b = 2 * (CO * dir - (CO * ^h)(dir * ^h))
	c = CO^2 - (CO - ^h)^2 - r^2
	(CO = O - C)

<Line-Cylinder intersection>

The cylinder consists of a tube and two discs. 
Line-Tube intersection and Line-Disk intersection already exists in another section, so check there.
