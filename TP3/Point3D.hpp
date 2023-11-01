
class Point3D {
private:
	float x, y, z; // private attributes
public:
	// constuctors
	Point3D(); // fill X Y Z with random values (from 0 to 100)
	Point3D(const float& newx, const float& newy, const float& newz);
	// fill XYZ values
	// Setters and getters
	void setXYZ(const float& newx, const float& newy, const float
		& newz);
	void setX(const float& newx);
	void setY(const float& newy);
	void setZ(const float& newz);
	float getX();
	float getY();
	float getZ();
	// other methods
	void print(); // prints the coordinates of the point
	float distanceTo(const Point3D& otherPoint3D);
};

constexpr size_t numberOfPoints = 10;

class Trajectory {
private:
	Point3D points[numberOfPoints];
public:
	void print(); // print the coordinates of all points
	Point3D& getPoint(const int& n); // returns the reference of point n
	float getTotalDistance();
	int setPointsOnLine();
};

