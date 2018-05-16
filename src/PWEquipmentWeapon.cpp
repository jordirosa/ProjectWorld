#include "PWEquipmentWeapon.h"

PWEquipmentWeapon::PWEquipmentWeapon(SDLGraphics* graphics, const char* name) : PWEquipment(graphics, name)
{
}

void PWEquipmentWeapon::setHand(Weapon::eWeaponEquipedHand hand)
{
	this->mHand = hand;

	this->mEquipedImage = this->mGraphics->loadImage(this->mImagesPath[this->mHand]);
	this->mEquipedImage->setHorizontalAlignment(this->mHorizontalAlignment[this->mHand]);
	this->mEquipedImage->setVerticalAlignment(this->mVerticalAlignment[this->mHand]);
}

PWEquipmentWeapon::~PWEquipmentWeapon()
{
}
