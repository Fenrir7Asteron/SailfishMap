pragma Singleton
import QtQuick 2.0
import QtPositioning 5.3
import QtLocation 5.0

QtObject {
    objectName: "sharedVariables"
    property variant center_coordinate: QtPositioning.coordinate(59.91, 10.75)
    property double zoom: Map.maximumZoomLevel / 1.4
    property variant item1Coordinate: QtPositioning.coordinate(59.91, 10.75)
    property string item1Text: "Kinda Long Oslo"
    property double topLeftLatitude: 57
    property double topLeftLongitude: 8
    property double bottomRightLatitude: 60
    property double bottomRightLongitude: 12
    property string areaColor: "transparent"
}
