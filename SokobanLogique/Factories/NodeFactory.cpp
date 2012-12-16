#include "NodeFactory.h"
#include "../Constants.h"
#include <osg/Geode>
#include <osgViewer/Viewer> 
#include <osg/Geometry> 
#include <osgDB/ReadFile> 
#include <osg\Texture2D>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <string>
#include <osg/StateAttribute>

///Cache
std::map<Sokoban::Type, osg::ref_ptr<osg::Node>> Sokoban::NodeFactory::_geoCache;
//Textures
std::map<Sokoban::Type, std::string> Sokoban::NodeFactory::_textures;
std::map<Sokoban::Type, std::string> Sokoban::NodeFactory::_switchTextures;

osg::ref_ptr<osg::PositionAttitudeTransform> Sokoban::NodeFactory::createNode(int x,int y,int z, Type element) {
	settingTextures();
	osg::ref_ptr<osg::PositionAttitudeTransform> postAtt = new osg::PositionAttitudeTransform();
	postAtt->addChild(getOrCreateGeode(element));

	//Translate the item to put it were the item should be.
	postAtt->setPosition(osg::Vec3(x,y,z));
	return postAtt;
}

void Sokoban::NodeFactory::settingTextures() {
	if (_textures.find(TARGET) != _textures.end())
		return;
	_textures[TARGET] = "target.png";
	_textures[BOX] = "box.jpg";
	_textures[WALL] = "brickscolorhx8.jpg";
	_textures[PLAYER] = "creeper.jpg";
	_textures[GROUND]  = "rs-ground00.jpg";	

	_textures[DIRECTION_BUTTON] = "arrow-right-double.png";
	_textures[LOAD_BUTTON] = "archive-extract.png";
	_textures[RELOAD_BUTTON] = "reload.png";
	_textures[ROTATE_LEFT_BUTTON] = "rotate_left.png";
	_textures[ROTATE_RIGHT_BUTTON] = "rotate_right.png";
	_textures[SAVE_BUTTON] = "archive-add.png";
	_textures[ZOOM_IN] = "add.png";
	_textures[ZOOM_OUT] = "remove.png";

	_switchTextures[DIRECTION_BUTTON] = "hover-arrow-right-double.png";
	_switchTextures[LOAD_BUTTON] = "hover-archive-extract.png";
	_switchTextures[RELOAD_BUTTON] = "hover-reload.png";
	_switchTextures[ROTATE_LEFT_BUTTON] = "hover-rotate_left.png";
	_switchTextures[ROTATE_RIGHT_BUTTON] = "hover-rotate_right.png";
	_switchTextures[SAVE_BUTTON] = "hover-archive-add.png";
	_switchTextures[ZOOM_IN] = "hover-add.png";
	_switchTextures[ZOOM_OUT] = "hover-remove.png";
}


bool Sokoban::NodeFactory::isAButton(Sokoban::Type type) {
	return type == Sokoban::DIRECTION_BUTTON ||
		type == Sokoban::LOAD_BUTTON ||
		type == Sokoban::RELOAD_BUTTON ||
		type == Sokoban::ROTATE_LEFT_BUTTON ||
		type == Sokoban::ROTATE_RIGHT_BUTTON ||
		type == Sokoban::SAVE_BUTTON ||
		type == Sokoban::ZOOM_IN ||
		type == Sokoban::ZOOM_OUT;
}

osg::ref_ptr<osg::Geometry> Sokoban::NodeFactory::createGround() {
	osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry();
	osg::ref_ptr<osg::Vec3Array> groundVertices = new osg::Vec3Array();

	/// Defining the points shaping the parallelepiped
	// An offset value is added to allow the 
	const float offset = 0.5;
	groundVertices->push_back(osg::Vec3(0 - offset, 0 - offset,  0));
	groundVertices->push_back(osg::Vec3(DEFAULT_LENGTH_X - offset, 0 - offset,  0));
	groundVertices->push_back(osg::Vec3(DEFAULT_LENGTH_X - offset, DEFAULT_LENGTH_Y - offset,  0));
	groundVertices->push_back(osg::Vec3(0 - offset, DEFAULT_LENGTH_Y - offset,  0));
	groundVertices->push_back(osg::Vec3(0 - offset, 0 - offset, -0.1));
	groundVertices->push_back(osg::Vec3(1 - offset, 0 - offset, -0.1));
	groundVertices->push_back(osg::Vec3(DEFAULT_LENGTH_X - offset, DEFAULT_LENGTH_Y - offset, -0.1));
	groundVertices->push_back(osg::Vec3(0 - offset, DEFAULT_LENGTH_Y - offset, -0.1));
	geometry->setVertexArray(groundVertices);


	/// Defining how the texture must be applied on the ground object
	osg::ref_ptr<osg::Vec2Array> texCoords = new osg::Vec2Array();
	texCoords->push_back(osg::Vec2(0,1));
	texCoords->push_back(osg::Vec2(1,1));
	texCoords->push_back(osg::Vec2(1,0));
	texCoords->push_back(osg::Vec2(0,0));

	texCoords->push_back(osg::Vec2(0,1));
	texCoords->push_back(osg::Vec2(1,1));
	texCoords->push_back(osg::Vec2(1,0));
	texCoords->push_back(osg::Vec2(0,0));

	texCoords->push_back(osg::Vec2(0,1));
	texCoords->push_back(osg::Vec2(1,1));
	texCoords->push_back(osg::Vec2(1,0));
	texCoords->push_back(osg::Vec2(0,0));

	texCoords->push_back(osg::Vec2(0,1));
	texCoords->push_back(osg::Vec2(1,1));
	texCoords->push_back(osg::Vec2(1,0));
	texCoords->push_back(osg::Vec2(0,0));

	texCoords->push_back(osg::Vec2(0,1));
	texCoords->push_back(osg::Vec2(1,1));
	texCoords->push_back(osg::Vec2(1,0));
	texCoords->push_back(osg::Vec2(0,0));

	texCoords->push_back(osg::Vec2(0,1));
	texCoords->push_back(osg::Vec2(1,1));
	texCoords->push_back(osg::Vec2(1,0));
	texCoords->push_back(osg::Vec2(0,0));
	geometry->setTexCoordArray(0, texCoords);


	/// Creating the faces tying the points of the parallepiped together
	osg::ref_ptr<osg::DrawElementsUInt> topFace = 
		new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	topFace->push_back(3);
	topFace->push_back(2);
	topFace->push_back(1);
	topFace->push_back(0);
	geometry->addPrimitiveSet(topFace);

	osg::ref_ptr<osg::DrawElementsUInt> bottomFace = 
		new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	bottomFace->push_back(7);
	bottomFace->push_back(6);
	bottomFace->push_back(5);
	bottomFace->push_back(4);
	geometry->addPrimitiveSet(bottomFace);


	osg::ref_ptr<osg::DrawElementsUInt> leftFace = 
		new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	leftFace->push_back(3);
	leftFace->push_back(7);
	leftFace->push_back(1);
	leftFace->push_back(0);
	geometry->addPrimitiveSet(leftFace);

	osg::ref_ptr<osg::DrawElementsUInt> rightFace = 
		new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	rightFace->push_back(2);
	rightFace->push_back(6);
	rightFace->push_back(5);
	rightFace->push_back(1);
	geometry->addPrimitiveSet(rightFace);

	osg::ref_ptr<osg::DrawElementsUInt> frontFace = 
		new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	frontFace->push_back(2);
	frontFace->push_back(6);
	frontFace->push_back(7);
	frontFace->push_back(3);
	geometry->addPrimitiveSet(frontFace);

	osg::ref_ptr<osg::DrawElementsUInt> backFace = 
		new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	backFace->push_back(1);
	backFace->push_back(4);
	backFace->push_back(5);
	backFace->push_back(0);
	geometry->addPrimitiveSet(backFace);

	return geometry;
}



osg::ref_ptr<osg::Geode> Sokoban::NodeFactory::setTexture(osg::ref_ptr<osg::Geode> geode, Sokoban::Type type, std::string& texturePath) {
	// create a simple material
	osg::Material *material = new osg::Material();
	if (isAButton(type))
		material->setEmission(osg::Material::FRONT, osg::Vec4(1, 1, 1, 1));
	else
		material->setEmission(osg::Material::FRONT, osg::Vec4(0.2, 0.2, 0.2, 0.5));
	// create a texture
	// load image for texture
	osg::ref_ptr<osg::Image> image = osgDB::readImageFile(texturePath);
	if (!image) {
		std::cerr << "Couldn't load texture : " << texturePath <<std::endl;
		return NULL;
	}
	//Create the texture putting the correct option and set the image
	osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	texture->setDataVariance(osg::Object::DYNAMIC);
	texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR_MIPMAP_LINEAR);
	texture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
	texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	texture->setImage(image);

	// assign the material and texture to the Geode
	osg::ref_ptr<osg::StateSet> stateSet = geode->getOrCreateStateSet();
	stateSet->setAttribute(material);
	stateSet->setMode(GL_LIGHTING,osg::StateAttribute::ON);
	stateSet->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);

	return geode;
}



osg::ref_ptr<osg::Node> Sokoban::NodeFactory::getOrCreateGeode(Type element) {
	if(_geoCache.find(element) != _geoCache.end()) {
		return _geoCache[element];
	}

	osg::ref_ptr<osg::Geode> noeudGeo = new osg::Geode();
	osg::ref_ptr<osg::ShapeDrawable> shape;
	std::string textureImage = TEXTURE_DIR;

	if (isAButton(element)) {
		std::map<Sokoban::Type, std::string>::iterator it = _textures.find(element);
		if (it != _textures.end())
			textureImage.append(it->second);
		else
			textureImage.append("default.jpg");
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), BUTTON_LENGTH_X, BUTTON_LENGTH_Y, BUTTON_LENGTH_Z));
		noeudGeo->addDrawable(shape);
		setTexture(noeudGeo, element, textureImage);

		osg::ref_ptr<osg::Geode> switchNoeudGeo = new osg::Geode();
		std::string switchTextureImage = TEXTURE_DIR;
		it = _switchTextures.find(element);
		if (it != _switchTextures.end())
			switchTextureImage.append(it->second);
		else
			switchTextureImage.append("default.jpg");
		osg::ref_ptr<osg::ShapeDrawable> switchShape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), BUTTON_LENGTH_X, BUTTON_LENGTH_Y, BUTTON_LENGTH_Z));
		switchNoeudGeo->addDrawable(switchShape);
		setTexture(switchNoeudGeo, element, switchTextureImage);

		osg::ref_ptr<osg::Switch> nodeSwitch = new osg::Switch();
		nodeSwitch->insertChild(0, noeudGeo); 
		nodeSwitch->insertChild(1, switchNoeudGeo);
		nodeSwitch->setChildValue(switchNoeudGeo, false);
		return nodeSwitch;
	} else {
		float lengthX, lengthY, lengthZ;
		//Switch on the element for texture and shape
		switch(element)
		{
		case GROUND :
			noeudGeo->addDrawable(createGround());
			break;
		case BOX:
			shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, -0.4), BOX_WIDTH));
			break;
		case WALL:
			lengthX = DEFAULT_LENGTH_X, lengthY = DEFAULT_LENGTH_Y, lengthZ = WALL_LENGTH_Z;
			shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0.55), lengthX, lengthY, lengthZ));
			break;
		case TARGET:
			lengthX = DEFAULT_LENGTH_X, lengthY = DEFAULT_LENGTH_Y, lengthZ = TARGET_LENGTH_Z;
			shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, -0.6), lengthX, lengthY, lengthZ));
			break;
		case PLAYER:
			shape = new osg::ShapeDrawable(new osg::Sphere(osg::Vec3(0, 0, -0.5), PLAYER_RADIUS));
			break;
		default:
			shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), DEFAULT_WIDTH));
			break;
		}
	}

	if (element != GROUND)
		noeudGeo->addDrawable(shape);

	std::map<Sokoban::Type, std::string>::iterator it = _textures.find(element);
	if (it != _textures.end())
		textureImage.append(it->second);
	else
		textureImage.append("default.jpg");

	noeudGeo = setTexture(noeudGeo, element, textureImage);

	_geoCache.insert(std::make_pair(element, noeudGeo));
	return  noeudGeo;
}