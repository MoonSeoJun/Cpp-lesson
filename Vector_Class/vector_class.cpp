#include <iostream>
#include <vector>

using namespace std;

class Point {
public:
	void Set_x(int _x) {
		x = _x;
	}

	void Set_y(int _y) {
		y = _y;
	}

	int Get_x() {
		return x;
	}

	int Get_y() {
		return y;
	}

private:
	int x, y;
};

int main() {
	Point pt;

	vector<Point> vec;

	int insert_x, insert_y;

	while (1) {
		cout << "x의 좌표와 y의 좌표를 입력해주세요 >> ";
		cin >> insert_x >> insert_y;

		if (insert_x == -1 && insert_y == -1) {
			cout << "\n-------------------------------" << endl;
			for (auto i : vec) {
				cout << "x의 좌표 >> " <<i.Get_x() << " || " << "y의 좌표 >> " <<i.Get_y() << endl;
			}
			break;
		}

		pt.Set_x(insert_x);
		pt.Set_y(insert_y);

		vec.push_back(pt);
	}

	return 0;
}