/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	// add "HelloWorld" splash screen"
	sprite = Sprite::create("HelloWorld.png");
	if (sprite == nullptr)
	{
		problemLoading("'HelloWorld.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		//// ρ]p
		//sprite->setRotation(45.0f);
		//// gk
		//sprite->setScale(3.0f, 4.0f);
		////ΆE½]
		//sprite->setFlippedX(true);
		////γΊ½]
		//sprite->setFlippedY(true);
		////ρ\¦
		//sprite->setVisible(true);
		////F’
		//sprite->setColor(Color3B(0xff, 0x00, 0x00));
		////s§Ύx
		//sprite->setOpacity(0xff);
		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}

	hydra = Sprite::create("Hydra.png");
	hydra->setPosition(Vec2(visibleSize.width - origin.x - 200, visibleSize.height - origin.y - 200));
	hydra->setScale(0.1f);

	this->addChild(hydra, 2);
	//updateπΔΡo·
	this->scheduleUpdate();

	i = 0;
	j = 255;
	return true;
}
void HelloWorld::update(float delta)
{
	Vec2 pos = hydra->getPosition();
	if (hydra->getPositionX() >= origin.x + 200 && hydra->getPositionY()>=visibleSize.height-200-origin.y )
		pos -= Vec2(vec, 0.0f);
	if (hydra->getPositionX() <= origin.x + 200 &&hydra->getPositionY() >= origin.y + 200)
		pos -= Vec2(0.0f, vec);
	if (hydra->getPositionX() <= visibleSize.width-origin.x - 200 && hydra->getPositionY() <= origin.y + 200)
		pos += Vec2(vec, 0.0f);
	if (hydra->getPositionX() >= visibleSize.width - origin.x - 200 && hydra->getPositionY() <= visibleSize.height - 200 - origin.y)
		pos += Vec2(0.0f, vec);
	hydra->setPosition(pos);
	/*
	i++;
	if (i > 60)
	{
		j-=255/5;
		hydra->setOpacity(j);
		i = 0;
	}*/

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
