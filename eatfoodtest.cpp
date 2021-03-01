#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <memory.h>

using namespace std;

/* 추상 클래스 */
class GameObject
{
protected:
	int distance; // 한번 이동거리
	int x, y; // 현재 위치
public:
	GameObject(int startX, int startY, int distance) { // 초기 위치와 이동거리 설정 
		this->distance = distance;
		this->x = startX; this->y = startY;
	}
	virtual ~GameObject() {	 } // 가상 소멸자

	virtual void move() = 0; // 이동한 후 새로운 위치로 x,y 변경
	virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject *p) { // 이 객체가 객체 p와 충돌했으면 true 리턴
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

/* Human 클래스에 GameObject 상속 */
class Human : public GameObject {
	char cIn; // 사용자의 값을 입력받을 변수를 설정 
public:
	Human(int x, int y, int distance) : GameObject(x, y, distance) { }
	~Human() { }
	void setCin(char c) { this->cIn = c; }
	virtual void move();
	virtual char getShape() { return 'H'; }
};

void Human::move() {

	switch (cIn) {
	case 'a': // 왼쪽
		this->y -= this->distance;
		break;

	case 's': // 아래쪽
		this->x += this->distance;
		break;

	case 'd': // 위쪽
		this->x -= this->distance;
		break;

	case 'f': // 오른쪽
		this->y += this->distance;
		break;
	}

}

