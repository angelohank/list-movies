import QtQuick 2.15

Row {
    id: root
    height: 50
    width: 240
    spacing: 10

    signal search( string filter );

    TextFieldCustom {
        id: textField

        height: parent.height
        width: parent.width - ( searchButton.width + root.spacing )
    }

    ButtonCustom {
        id: searchButton

        height: parent.height
        width: parent.width * 0.1
        src: "qrc:/resources/images/SEARCH-ICON.png"

        onClicked: {
            root.search( textField.text );
            textField.text = ""
        }
    }
}
