function XMLHttpRequest_test()
{
    var request = new XMLHttpRequest();
    //var response = new XMLHttpRequest();
    request.open("POST", "http://127.0.0.1:31416",false);
    request.send("<boinc_gui_rpc_request><exchange_versions><major>BOINC_MAJOR_VERSION</major><minor>BOINC_MINOR_VERSION</minor><release>BOINC_RELEASE</release></exchange_versions></boinc_gui_rpc_request>");
    if(request.status !== 200) throw new Error(request.statusText);
    var type = request.getResponseHeader("Content-Type")
    if(!type.match(/^text/))
	{
		throw new Error("Expected textual response; got: " + type);
	}
} 


