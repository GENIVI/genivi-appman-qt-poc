import QtQuick 2.7
import GeniviAppFw 1.0

Item {
    width: 600
    height: 200

    Text {
        anchors.centerIn: parent
        text: "Connect to the GENIVI Application Manager interface via d-bus"
    }

    /* Same structure as the QtAS Application Manager */
    ListModel {
        id: appsModel

        ListElement {
            applicationId: "org.genivi.TunerAMFM"
            name: "Radio"
        }
        ListElement {
            applicationId: "org.genivi.TunerDAB"
            name: "DAB"
        }
        ListElement {
            applicationId: "org.genivi.Navigation"
            name: "Navigation"
        }
        ListElement {
            applicationId: "org.genivi.Settings"
            name: "Settings"
        }
        ListElement {
            applicationId: "org.genivi.Telephone"
            name: "Telephone"
        }
    }

    Connections {
        target: GeniviAppMan
        onLaunchApplication: console.log("Launching " + id);
    }

    Component.onCompleted: {
        GeniviAppMan.model = appsModel;
    }
}
