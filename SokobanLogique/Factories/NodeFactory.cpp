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
std::map<Sokoban::Type,osg::ref_ptr<osg::Geode>> Sokoban::NodeFactory::_geoCache;

osg::ref_ptr<osg::PositionAttitudeTransform> Sokoban::NodeFactory::createNode(int x,int y,int z, Type element) {

	osg::ref_ptr<osg::PositionAttitudeTransform> postAtt = new osg::PositionAttitudeTransform();
	postAtt->addChild(getOrCreateGeode(element));

	//Translate the item to put it were the item should be.
	postAtt->setPosition(osg::Vec3(x,y,z));
	return postAtt;
}

/// Creates and returns a ground object.
/// <returns>Returns a geometry object representing a Ground object.</returns>
osg::ref_ptr<osg::Geometry> Sokoban::NodeFactory::createGround() {
	osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry();
	osg::ref_ptr<osg::Vec3Array> groundVertices = new osg::Vec3Array();

	/// Defining the points shaping the parallelepiped
	groundVertices->push_back(osg::Vec3(0 - 0.5, 0 - 0.5,  0));
	groundVertices->push_back(osg::Vec3(1 - 0.5, 0 - 0.5,  0));
	groundVertices->push_back(osg::Vec3(1 - 0.5, 1 - 0.5,  0));
	groundVertices->push_back(osg::Vec3(0 - 0.5, 1 - 0.5,  0));
	groundVertices->push_back(osg::Vec3(0 - 0.5, 0 - 0.5, -0.1));
	groundVertices->push_back(osg::Vec3(1 - 0.5, 0 - 0.5, -0.1));
	groundVertices->push_back(osg::Vec3(1 - 0.5, 1 - 0.5, -0.1));
	groundVertices->push_back(osg::Vec3(0 - 0.5, 1 - 0.5, -0.1));
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

	// assign the material and texture to the sphere
	osg::ref_ptr<osg::StateSet> stateSet = geode->getOrCreateStateSet();
	stateSet->setAttribute(material);
	stateSet->setMode(GL_LIGHTING,osg::StateAttribute::ON);
	stateSet->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
	_geoCache.insert(std::make_pair(type, geode));
	return geode;
}

osg::ref_ptr<osg::Node> Sokoban::NodeFactory::getOrCreateGeode(Type element) {
	if(_geoCache.find(element) != _geoCache.end()) {
		return _geoCache[element];
	}


	osg::ref_ptr<osg::Switch> nodeSwitch = new osg::Switch();

	osg::ref_ptr<osg::ShapeDrawable> shape;
	std::string textureImage = TEXTURE_DIR;
	osg::ref_ptr<osg::Geode> noeudGeo = new osg::Geode();

	std::string switchTextureImage = TEXTURE_DIR;
	osg::ref_ptr<osg::ShapeDrawable> switchShape;
	osg::ref_ptr<osg::Geode> SwitchNoeudGeo;

	//Switch on the element for texture and shape
	switch(element)
	{
	case GROUND :
		noeudGeo->addDrawable(createGround());
		textureImage.append("rs-ground00.jpg");
		break;
	case BOX:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, -0.4),0.9));
		textureImage.append("box.jpg");
		break;
	case WALL:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0.55),1,1,1.4));
		textureImage.append("brickscolorhx8.jpg");
		break;
	case TARGET:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, -0.6), 1,1,1));
		textureImage.append("target.png");
		break;
	case PLAYER:
		shape = new osg::ShapeDrawable(new osg::Sphere(osg::Vec3(0, 0, -0.5), 0.4));
		textureImage.append("creeper.jpg");
		break;
	case DIRECTION_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0),1,1, 0));
		noeudGeo->addDrawable(shape);
		textureImage.append("arrow-right-double.png");
		break;
	case SAVE_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
		textureImage.append("floppy.jpg");
		break;
	case ZOOM_IN:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
		textureImage.append("zoom_in.png");
		break;
	case ZOOM_OUT:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
		textureImage.append("zoom_out.png");
		break;
	case LOAD_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
		textureImage.append("load.png");
		break;
	case RELOAD_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
		textureImage.append("refresh_icon.jpg");
		break;
	case ROTATE_LEFT_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
		textureImage.append("rotate_left.png");
		break;
	case ROTATE_RIGHT_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
		textureImage.append("rotate_right.png");
		break;
	default:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1));
		textureImage.append("default.jpg");
		break;
	}
	if (element != GROUND)
		noeudGeo->addDrawable(shape);

	if (element == DIRECTION_BUTTON ||
		element == ZOOM_IN ||
		element == ZOOM_OUT ||
		element == SAVE_BUTTON ||
		element == ROTATE_LEFT_BUTTON ||
		element == ROTATE_RIGHT_BUTTON ||
		element == LOAD_BUTTON ||
		element == RELOAD_BUTTON) {
			SwitchNoeudGeo = new osg::Geode();
			switchTextureImage.append("default.jpg");
			switchShape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1.5, 1.5, 0));
			SwitchNoeudGeo->addDrawable(switchShape);
			nodeSwitch->addChild(noeudGeo);
			nodeSwitch->addChild(SwitchNoeudGeo);
			return nodeSwitch;
	}

	setTexture(noeudGeo, element, textureImage);
	return noeudGeo;
}