function loadXMLDoc(fileName) {
    try {//Internet Explorer
        xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
        xmlDoc.async = "false";
        //加载 XML文档,获取XML文档对象
        xmlDoc.load(fileName);
    } catch (e) {
        try {//Google Chrome
            var xmlhttp = new XMLHttpRequest();
            xmlhttp.open("GET", fileName, false);
            xmlhttp.send(null);
            xmlDoc = xmlhttp.responseXML;
        } catch (e) {
            alert("您的浏览器不能正常加载文件。请切换到兼容模式，或者更换浏览器");
        }
    }

    return xmlDoc;

}
