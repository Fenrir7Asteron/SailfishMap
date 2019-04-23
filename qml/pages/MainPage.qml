import QtQuick 2.2
import QtQuick.Window 2.0
import Sailfish.Silica 1.0
import QtPositioning 5.3
import QtLocation 5.0


Page {
    id: page

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
        id: map
        objectName: "map"
        anchors.fill: parent
        plugin: osmPlugin
        property variant center_coord: QtPositioning.coordinate(59.91, 10.75)
        center: center_coord // Oslo
        property double zoom: maximumZoomLevel / 1.4
        zoomLevel: zoom


        MapRectangle {
            id: mapRectangle
            objectName: "transparentMapRectangle"
            color: "transparent"
            opacity: 0.05
            topLeft {
                latitude: 57
                longitude: 8
            }
            bottomRight {
                latitude: 60
                longitude: 12
            }

            Component.onCompleted: {
                //map.center_coord = QtPositioning.coordinate((topLeft.latitude + bottomRight.latitude) / 2, (topLeft.longitude + bottomRight.longitude) / 2)
                //map.zoom = map.maximumZoomLevel - (7.5 + Math.log(Math.max(Math.abs(topLeft.latitude - bottomRight.latitude), Math.abs(topLeft.longitude - bottomRight.longitude))) / Math.log(1.8))
                //console.log(map.maximumZoomLevel, (Math.max(Math.abs(topLeft.latitude - bottomRight.latitude), Math.abs(topLeft.longitude - bottomRight.longitude))), map.zoom)
                console.log(opacity)
            }

            onObjectNameChanged: {
                map.center_coord = QtPositioning.coordinate((topLeft.latitude + bottomRight.latitude) / 2, (topLeft.longitude + bottomRight.longitude) / 2)
                map.zoom = map.maximumZoomLevel - (7.5 + Math.log(Math.max(Math.abs(topLeft.latitude - bottomRight.latitude), Math.abs(topLeft.longitude - bottomRight.longitude))) / Math.log(1.8))
                console.log(topLeft.latitude, topLeft.longitude)
            }
        }

        gesture.enabled: true
        PinchArea {
            id: pincharea

            property double oldZoom

             anchors.fill: parent

             function calcZoomDelta(zoom, percent) {
                 return zoom + Math.log(percent)/Math.log(2)
             }

             onPinchStarted: {
                oldZoom = map.zoomLevel
             }

             onPinchUpdated: {
                map.zoomLevel = calcZoomDelta(oldZoom, pinch.scale)
             }

             onPinchFinished: {
                map.zoomLevel = calcZoomDelta(oldZoom, pinch.scale)
             }
        }

        MapQuickItem {
            id: item1
            objectName: "item1"
            coordinate: QtPositioning.coordinate(59.91, 10.75)
            anchorPoint.x: image1.width / 2
            anchorPoint.y: image1.height
            sourceItem: Image {
                id: image1
                width: 70
                height: 70
                source: "qrc:/icons/placeholder.svg"
                Rectangle {
                    id: containing_rect
                    objectName: "item1TextBox"
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
                        font.pixelSize: 40

                        text: parent.text
                        objectName: "memo"
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
                if (Qt.colorEqual(mapRectangle.color, "transparent")) {
                    map.center_coord = coordinate
                }
            }
        }
    }

    function increase_zoom(zoom, percent) {
        return zoom + 0.5
    }

    function decrease_zoom(zoom, percent) {
        return zoom - 0.5
    }
    Column {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 20
        spacing: 50
        Button {
            id: increase
            width: 80
            height: 80
            Image {
                width: 80
                height: 80
                source: "qrc:/icons/add-searching.svg"
            }
            onClicked: map.zoomLevel = increase_zoom(map.zoomLevel)
        }

        Button {
            id: decrease
            width: 80
            height: 80
            Image {
                width: 80
                height: 80
                source: "qrc:/icons/delete-searching.svg"
            }
            onClicked: map.zoomLevel = decrease_zoom(map.zoomLevel)
        }
    }
}


/*
Page {
 Column {
 anchors.fill: parent
 SilicaWebView {
 id: webView
 width: parent.width
 height: parent.height - urlField.height
 url: "http://omprussia.ru"
 }
 TextField {
 id: urlField
 inputMethodHints: Qt.ImhUrlCharactersOnly
 text: "http://omprussia.ru"
 label: webView.title
 EnterKey.onClicked: {
 webView.url = text
 parent.focus = true
 }
 }
 }
}
*/
