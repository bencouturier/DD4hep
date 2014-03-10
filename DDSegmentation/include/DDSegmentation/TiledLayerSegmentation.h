/*
 * TiledLayerSegmentation.h
 *
 *  Created on: Mar 10, 2014
 *      Author: cgrefe
 */

#ifndef DDSegmentation_TILEDLAYERSEGMENTATION_H_
#define DDSegmentation_TILEDLAYERSEGMENTATION_H_

#include "DDSegmentation/Segmentation.h"

// C/C++ includes
#include <string>
#include <vector>

namespace DD4hep {
namespace DDSegmentation {

class TiledLayerSegmentation: public Segmentation {
public:
	/// Helper class to store x and y dimensions of a layer
	struct LayerDimensions {
		LayerDimensions(double x = 1., double y = 1.) :
			x(x), y(y) {}
		double x, y;
	};

	/// Default constructor passing the encoding string
	TiledLayerSegmentation(const std::string& cellEncoding = "");
	/// destructor
	virtual ~TiledLayerSegmentation();

	/// determine the position based on the cell ID
	virtual Vector3D position(const CellID& cellID) const;
	/// determine the cell ID based on the position
	virtual CellID cellID(const Vector3D& localPosition, const Vector3D& globalPosition,
			const VolumeID& volumeID) const;

	/// access the default grid size in X
	double gridSizeX() const {
		return _gridSizeX;
	}
	/// access the default grid size in Y
	double gridSizeY() const {
		return _gridSizeY;
	}

	/// access the actual grid size in X for a given layer
	double layerGridSizeX(int layerIndex) const;
	/// access the actual grid size in Y for a given layer
	double layerGridSizeY(int layerIndex) const;

	/// access the encoding field name used for X
	const std::string& identifierX() const {
		return _identifierX;
	}
	/// access the encoding field name used for Y
	const std::string& identifierY() const {
		return _identifierY;
	}
	/// access the encoding field name used for Y
	const std::string& identifierLayer() const {
		return _identifierLayer;
	}

	/// access to the dimensions of the given layer
	LayerDimensions layerDimensions(int layerIndex) const;

	/// set the default grid size in X
	void setGridSizeX(double cellSize) {
		_gridSizeX = cellSize;
	}
	/// set the default grid size in Y
	void setGridSizeY(double cellSize) {
		_gridSizeY = cellSize;
	}

	/// set the encoding field name used for X
	void setIdentifierX(const std::string& name) {
		_identifierX = name;
	}
	/// set the encoding field name used for Y
	void setIdentifierY(const std::string& name) {
		_identifierY = name;
	}
	/// set the encoding field name used for layer
	void setIdentifierLayer(const std::string& name) {
		_identifierLayer = name;
	}

	/// set the dimensions of the given layer
	void setLayerDimensions(int layerIndex, double x, double y);



protected:
	double _gridSizeX; /// default grid size in X
	double _gridSizeY; /// default grid size in Y
	std::string _identifierX; /// encoding field used for X
	std::string _identifierY; /// encoding field used for Y
	std::string _identifierLayer; /// encoding field used for the layer
	std::vector<int> _layerIndices; /// list of valid layer identifiers
	std::vector<double> _layerDimensionsX; /// list of layer x dimensions
	std::vector<double> _layerDimensionsY; /// list of layer y dimensions

	/// helper method to calculate optimal cell size based on total size
	static double calculateOptimalCellSize(double nominalCellSize, double totalSize);
	/// helper method to calculate offset of bin 0 based on the total size
	static double calculateOffset(double cellSize, double totalSize);
};

} /* namespace DDSegmentation */
} /* namespace DD4hep */

#endif /* TILEDLAYERSEGMENTATION_H_ */
