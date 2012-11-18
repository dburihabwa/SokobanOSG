#include "NodeFactory.h"
#include "../Constants.h"
#include <osg/Geode>
#include <osgViewer/Viewer> 
#include <osg/Geometry> 
#include <osgDB/ReadFile> 
#include <osg\Texture2D>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/PositionAttitudeTransform>
#include <string>

///Cache
std::map<Sokoban::Type,osg::ref_ptr<osg::Geode>> Sokoban::NodeFactory::_geoCache;

osg::ref_ptr<osg::Node> Sokoban::NodeFactory::createNode(int x,int y,int z, Type element) {

	osg::ref_ptr<osg::PositionAttitudeTransform> postAtt = new osg::PositionAttitudeTransform();
	postAtt->addChild(getOrCreateGeode(element));

	//Translate the item to put it were the item should be.
	postAtt->setPosition(osg::Vec3(x,y,z));
	return postAtt;
}

osg::ref_ptr<osg::Geode> Sokoban::NodeFactory::getOrCreateGeode(Type element) {
	if(_geoCache.find(element) != _geoCache.end()) {
		return _geoCache[element];
	}
	osg::ref_ptr<osg::ShapeDrawable> shape;
	std::string textureImage = TEXTURE_DIR;
	//Switch on the element for texture and shape
	switch(element)
	{
	case GROUND :
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1,1,0.1));
		textureImage.append("rs-ground00.jpg");
		break;
	case BOX:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0),0.9));
		textureImage.append("box.jpg");
		break;
	case WALL:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0),1,1,1.2));
		textureImage.append("brickscolorhx8.jpg");
		break;
	case TARGET:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0.05), 1,1,0.05));
		textureImage.append("target.png");
		break;
	case PLAYER:
		shape = new osg::ShapeDrawable(new osg::Sphere(osg::Vec3(0, 0, 0), 0.4));
		textureImage.append("creeper.jpg");
		break;
	case DIRECTION_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0),1,1, 0));
		textureImage.append("arrow.jpg");
		break;
	case SAVE_BUTTON:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1, 1, 0));
		textureImage.append("floppy.jpg");
		break;
	case ZOOM_IN:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1, 1, 0));
		textureImage.append("zoom_in.png");
		break;
	case ZOOM_OUT:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1, 1, 0));
		textureImage.append("zoom_in.png");
		break;
	default:
		shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0), 1));
		textureImage.append("default.jpg");
		break;
	}
	osg::ref_ptr<osg::Geode> noeudGeo = new osg::Geode;
	noeudGeo->addDrawable(shape);

	// create a simple material
	osg::Material *material = new osg::Material();
	material->setEmission(osg::Material::FRONT, osg::Vec4(0.8, 0.8, 0.8, 1.0));
	// create a texture
	// load image for texture
	osg::ref_ptr<osg::Image> image = osgDB::readImageFile(textureImage);
	if (!image) {
		std::cout << "Couldn't load texture : " << textureImage <<std::endl;
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
	osg::ref_ptr<osg::StateSet> sphereStateSet = noeudGeo->getOrCreateStateSet();
	sphereStateSet->setAttribute(material);
	sphereStateSet->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
	_geoCache.insert(std::make_pair(element,noeudGeo));
	return noeudGeo;
}