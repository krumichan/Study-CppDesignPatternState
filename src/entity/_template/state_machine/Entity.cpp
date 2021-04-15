#include "Entity.h"

/**
 * コンストラクタ
 */
Entity::Entity()
{
	this->state = "IDLE";
	this->x = 0;
	this->y = 0;
}

/**
 * デストラクタ
 */
Entity::~Entity()
{

}

/**
 * このインスタンスを実行する関数
 */
void Entity::Update()
{
	UpdateHandle();
	this->state = UpdateState();
}
