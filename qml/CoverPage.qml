import QtQuick 2.0
import QtPositioning 5.3
import QtLocation 5.0
import Sailfish.Silica 1.0

CoverBackground {
    Plugin {
     id: osmPlugin
     allowExperimental: true
     preferred: ["osm"]

     PluginParameter { name: "osm.useragent"
     value: "My great Qt OSM application"
     }
     PluginParameter { name: "osm.mapping.host"
     value: "http://osm.tile.server.address/"
     }
     PluginParameter { name: "osm.mapping.copyright"
     value: "All mine"
     }
     PluginParameter { name: "osm.routing.host"
     value: "http://osrm.server.address/viaroute"
     }
     PluginParameter { name: "osm.geocoding.host"
     value: "http://geocoding.server.address"
     }
    }


    Map {
        id: cover_map
        objectName: "cover_map"
        anchors.fill: parent
        plugin: osmPlugin
        property variant center_coord: QtPositioning.coordinate(59.91, 10.75)
        center: center_coord // Oslo
        property double zoom: maximumZoomLevel / 1.4
        zoomLevel: zoom

        MapRectangle {
            id: cover_mapRectangle
            objectName: "cover_transparentMapRectangle"
            color: "transparent"
            opacity: 0.05
            property double lLatitude: 57
            property double lLongitude: 8
            property double rLatitude: 60
            property double rLongitude: 12
            topLeft {
                latitude: lLatitude
                longitude: lLongitude
            }
            bottomRight {
                latitude: rLatitude
                longitude: rLongitude
            }
        }

        MapQuickItem {
            id: cover_item1
            objectName: "cover_item1"
            coordinate: QtPositioning.coordinate(59.91, 10.75)
            anchorPoint.x: image1.width / 2
            anchorPoint.y: image1.height
            sourceItem: Image {
                id: image1
                width: 50
                height: 50
                source: "qrc:/icons/placeholder.svg"
                Rectangle {
                    id: containing_rect
                    objectName: "cover_item1TextBox"
                    property string text

                    anchors.bottom: parent.top
                    anchors.bottomMargin: 5
                    anchors.horizontalCenter: parent.horizontalCenter

                    height: text_field.paintedHeight

                    color: "#4000CBA9"
                    antialiasing: true
                    border.width: 2
                    border.color: "green"
                    text: "Kinda Long Oslo"

                    Text {
                        id: text_field
                        anchors.top: parent.top
                        anchors.left: parent.left

                        height: parent.height
                        width: parent.width
                        font.weight: Font.ExtraBold
                        font.pixelSize: 30

                        text: parent.text
                        wrapMode: Text.WordWrap
                        horizontalAlignment: Text.AlignHCenter
                    }

                    Component.onCompleted: {
                        if (text_field.paintedWidth > 200) {
                            width = 200
                        } else {
                            width = text_field.paintedWidth
                        }
                    }
                }
            }
            onObjectNameChanged: {
                if (Qt.colorEqual(cover_mapRectangle.color, "transparent")) {
                    cover_map.center_coord = coordinate
                }
            }
        }
    }
}
