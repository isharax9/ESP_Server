async function callESP(status){
   const response = await fetch ("http://192.168.1.15?status="+status);
}