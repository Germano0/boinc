function XMLHttpRequest_test()
{
    var request = new XMLHttpRequest();
    request.open("POST", "http://127.0.0.1:31416"); // with false it triggers network error
    request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    request.send("<boinc_gui_rpc_request><exchange_versions><major>BOINC_MAJOR_VERSION</major><minor>BOINC_MINOR_VERSION</minor><release>BOINC_RELEASE</release></exchange_versions></boinc_gui_rpc_request>");
    /* I don't know how this function can iterate without a for cycle.
     * The code is based on some examples from book "JavaScript the definitive guide"
     */
    request.onreadystatechange = function()
    {
        if(request.readyState === 4 && request.status === 200)
        {
            var type = request.getResponseHeader("response");
            console.log(type);
            console.log(request);
            alert(request.responseText);
        }
    }
} 

