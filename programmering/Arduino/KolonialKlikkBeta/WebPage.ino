
void root()
{
  Serial.println(">> Creating root page");

  String rootPage = String();

  rootPage += "<!DOCTYPE html><html><head>";
  rootPage += "<meta charset='utf-8'>";
  rootPage += "<meta http-equiv='X-UA-Compatible' content='IE=edge'>";
  rootPage += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  rootPage += "<meta name='description' content=''>";
  rootPage += "<meta name='author' content=''>";
  rootPage += "<title>Kolonial Klikk</title>";
  rootPage += "<script type='text/javascript'>";
  rootPage += "function transferField(val) { document.wifiForm.ssid.value = val; }";
  rootPage += "function passFocus() { document.getElementById('pass').focus(); }";
  rootPage += "</script></head><style>";
  rootPage += "div {width:50%; position: relative; margin:auto; padding-top:10%; font-weight:300;}";
  rootPage += "p {font-size: 18px; font-weight:300;}";
  rootPage += "select {height:50px; width:100%; font-size:20px;}";
  rootPage += "input[type=submit] {width: 100%; height: 50px; background-color: #FDA42F; color:#fff; font-size:20px; margin-top:30px; cursor:pointer;}";
  rootPage += "input[type=text] {width: 100%; height:30px; border:none; font-size:20px;}";
  rootPage += "input[type=password] {width: 100%; height:30px; border:none; border-bottom:1px solid rgba(0,0,0,0.2); font-size:24px; padding:1%;}";
  rootPage += "input[type=password]:focus {border: 3px solid #555;}";
  rootPage += "h3 {font-weight: 300;} footer {text-align:center;} svg {width:200px;}";
  rootPage += "</style><body style='font-family: Helvetica, sans-serif; font-weight: 400; '>";
  rootPage += "<div><h1>Kolonial Klikk</h1>";
  rootPage += "<h3>1. Finn nettverket ditt i listen under</h3>";
  rootPage += "<h3>2. Skriv inn passordet som du bruker for å koble deg til nettverket</h3>";
  rootPage += "<h3>3. Trykk på knappen for å koble til</h3>";
  rootPage += "<select onchange='transferField(this.value);passFocus();'>";
  rootPage += "<option value="">Velg et nettverk...</option>";


  for (int i = 0; i < ScannedNetworks; ++i)
  {
    if (indicies[i] == -1)
      continue;

    rootPage += "<option value='";
    rootPage += WiFi.SSID(indicies[i]);
    rootPage += "'>";
    rootPage += WiFi.SSID(indicies[i]);
    rootPage += "</option>";
  }

  rootPage += "</select>";
  rootPage += "<form name='wifiForm' method='get' action='reply'>";
  rootPage += "<input name='ssid' type='text' id='ssid' value='' style='display: none; '>";
  rootPage += "<p>Passord:</p>";
  rootPage += "<input name='pass' type='password' id='pass' value=''>";
  rootPage += "<br><input type='submit' value='Koble til'><br></form>";
  rootPage += "</div><footer><svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 700 700'>";
  rootPage += "<style>.a{fill:#413746;}.b{fill:#FEA500;}</style><polygon points='58 343.4 34.2 343.4 34.2 217.1 58.3 217.1 58.3 278.1 106.2 216.9 135.6 216.9 85.7 281.1 135 343.4 105.6 343.4 58 283.6 ' class='a'/>";
  rootPage += "<path d='M178.9 256.8c-24.6 0-44.5 19.9-44.5 44.5 0 24.6 19.9 44.5 44.5 44.5s44.5-19.9 44.5-44.5C223.4 276.7 203.5 256.8 178.9 256.8zM178.9 325.4c-12.8 0-23.1-10.9-23.1-24.2 0-13.4 10.4-24.2 23.1-24.2 12.8 0 23.1 10.9 23.1 24.2C202 314.6 191.7 325.4 178.9 325.4z' class='a'/>";
  rootPage += "<path d='M326.3 256.8c-24.6 0-44.5 19.9-44.5 44.5 0 24.6 19.9 44.5 44.5 44.5s44.5-19.9 44.5-44.5C370.7 276.7 350.8 256.8 326.3 256.8zM326.3 325.4c-12.8 0-23.1-10.9-23.1-24.2 0-13.4 10.4-24.2 23.1-24.2s23.1 10.9 23.1 24.2C349.4 314.6 339 325.4 326.3 325.4z' class='a'/>";
  rootPage += "<path d='M236.1 217.1h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L236.1 217.1z' class='a'/>";
  rootPage += "<path d='M629.1 217.1h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L629.1 217.1z' class='a'/>";
  rootPage += "<path d='M632 217.1h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L632 217.1z' class='a'/>";
  rootPage += "<path d='M384 258.4h23v7.5c0 0 10.5-9.4 24.1-9.1 0 0 30.7-2.2 31.9 27.4v59.6h-22.4l-0.3-50.3c0 0-0.1-16.6-15.6-16.9 0 0-16 0.5-17.6 15.7l0 51.7h-23.3L384 258.4z' class='a'/>";
  rootPage += "<rect x='482.8' y='258.4' width='23.4' height='85.8' class='a'/>";
  rootPage += "<circle cx='494.4' cy='228.1' r='14.4' class='a'/>";
  rootPage += "<polygon points='59.2 484.4 35.4 484.4 35.4 358.1 59.5 358.1 59.5 419 107.4 357.8 136.8 357.8 86.9 422.1 136.2 484.4 106.9 484.4 59.2 424.6 ' class='a'/>";
  rootPage += "<path d='M144.6 359.9h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L144.6 359.9z' class='a'/>";
  rootPage += "<rect x='199.6' y='399.4' width='23.4' height='85.8' class='a'/>";
  rootPage += "<circle cx='212.3' cy='369.1' r='14.4' class='a'/>";
  rootPage += "<path d='M592.8 258.4V269c-7.4-7.3-17.4-11.8-28.3-11.8 -23 0-41.6 19.7-41.6 44.1 0 24.3 18.6 44.1 41.6 44.1 11 0 20.9-4.5 28.3-11.8V344h19.5v-85.5H592.8zM567 325.2c-12.6 0-22.9-10.9-22.9-24.3s10.2-24.3 22.9-24.3 22.9 10.9 22.9 24.3S579.7 325.2 567 325.2z' class='a'/>";
  rootPage += "<path d='M565.5 377.2c4-0.3 7.6 1.6 10.9 4.2 8.1 6.4 16.2 12.7 24.2 19.2 2.3 1.8 3.7 1.8 6-0.1 7.9-6.6 16.1-12.9 24.2-19.2 8-6.3 17.9-5.5 23.7 1.9 5.6 7.1 4.2 16.8-3.6 23.1 -14.7 11.8-29.6 23.4-44.4 35.2 -2.1 1.7-3.5 1.8-5.6 0 -15.3-12.2-30.7-24.1-45.9-36.3 -5.3-4.2-7-11.3-4.8-17.7C552.4 381.2 558.1 377.2 565.5 377.2z' class='b'/>";
  rootPage += "<path d='M549 472.6c0-1.9 0-3.9 0-5.8 3.1-9.5 8-13.1 17.8-13.1 24.9 0 49.8 0 74.7 0 7.6 0 13.6 4.2 15.9 10.7 2.2 6.3 0.3 13.2-4.9 17.6 -3 2.6-6.6 3.7-10.5 3.7 -25.7 0-51.4 0.1-77.1 0C556.8 485.7 551.8 481.3 549 472.6z' class='b'/>";
  rootPage += "<polygon points='326.9 484.1 296 443.6 324.5 405.5 297.2 405.2 268.6 440.5 268.6 379.6 268.5 379.6 268.5 446.4 299.1 484.3 ' class='a'/>";
  rootPage += "<polygon points='244.6 358.1 244.6 484.4 268.4 484.4 268.6 424.9 268.6 424.9 268.6 358.1 ' class='a'/>";
  rootPage += "<polygon points='424 484.1 393.1 443.6 421.6 405.5 394.3 405.2 365.7 440.5 365.7 379.6 365.7 379.6 365.7 446.4 396.2 484.3 ' class='a'/>";
  rootPage += "<polygon points='341.7 358.1 341.7 484.4 365.5 484.4 365.7 424.9 365.7 424.9 365.7 358.1 ' class='a'/>";
  rootPage += "<path d='M500.6 364.5c-2.6 4.7-5.3 9.4-7.9 14.2 -0.8 1.5-1.6 3-2.5 4.7 -1.6-0.9-3-1.6-4.6-2.5 3.4-6.3 6.8-12.7 10.3-19C497.5 362.8 499 363.6 500.6 364.5z' class='b'/>";
  rootPage += "<path d='M437.3 413.7c-0.4-1.2-0.8-2.8-1.2-4.1 7-2.1 13.9-4.1 20.9-6.2 0.3 1.1 0.8 2.7 1.1 4.1C451.5 409.5 444.5 411.6 437.3 413.7z' class='b'/>";
  rootPage += "<path d='M494.9 391.9c7-2.1 13.9-4.1 20.8-6.1 0.4 1.4 0.9 3 1.3 4.4 -6.8 2-13.8 4.1-20.9 6.2C495.7 395.1 495.3 393.5 494.9 391.9z' class='b'/>";
  rootPage += "<path d='M464.9 360.6c1.2-0.3 2.7-0.8 4.1-1.2 2 6.8 4 13.6 6.1 20.5 -1.3 0.3-2.9 0.6-4.3 1C469 374.5 467 367.6 464.9 360.6z' class='b'/>";
  rootPage += "<path d='M441.4 382c0.8-1.5 1.5-2.8 2.4-4.3 6.2 3.4 12.5 6.7 18.8 10.2 -0.7 1.4-1.5 2.8-2.4 4.3C454.1 388.8 447.9 385.5 441.4 382z' class='b'/>";
  rootPage += "<path d='M494.3 410.7c0.8-1.5 1.6-2.9 2.4-4.4 6.3 3.4 12.5 6.8 18.9 10.2 -0.8 1.5-1.6 2.9-2.4 4.4C506.9 417.5 500.7 414.1 494.3 410.7z' class='b'/>";
  rootPage += "<path d='M478.9 485.5c-0.1-1-0.3-1.9-0.2-2.6 0.6-4.7-1.3-8.4-4.3-12 -6-7.3-11.6-14.8-17.3-22.4 -1-1.3-1.7-3.1-1.8-4.7 -0.1-1.4 0.6-3.3 1.6-4.2 1.5-1.2 3.7-1.5 5.4 0.1 1.8 1.6 3.6 3.3 5.4 5 1.2 1.1 2.3 2.6 4.2 1.8 1.9-0.8 1.7-2.6 1.6-4.2 -0.3-11.1-0.7-22.1-1-33.2 0-0.6 0-1.1 0-1.7 0.1-3.4 1.3-4.8 4.2-4.9 3-0.1 5.1 1.6 5.3 4.6 0.2 2.8 0.2 5.6 0.3 8.4 0.1 4.3 0.2 8.5 0.4 12.8 0.1 2.7 1 3.5 3.6 3.5 1.3 0 2.6-0.1 3.9-0.1 1.8 0 3.8-0.7 4.3 2.2 0.1 0.6 1.7 1.1 2.7 1.2 1.4 0.2 2.8 0 4.2-0.1 1.9-0.2 3.4-0.1 4.4 2.1 0.3 0.8 2 1.3 3.1 1.4 1.9 0.2 3.8-0.1 5.6-0.1 3.6 0 5.9 2.2 6 5.8 0.2 6.4 0.5 12.8 0.5 19.2 0 1.7-0.8 3.5-1.5 5.1 -2 5-4.1 10-6.3 15 -0.3 0.6-1.3 1.3-2 1.3C500.7 485 490 485.2 478.9 485.5z' class='b'/>";
  rootPage += "</svg></footer>";
  rootPage += "</body></html>";

  APserver.send(200, "text/html", rootPage);
}

void reply()
{
  Serial.println(">> Creating reply page");

  String replyPage = String();
  String newSSID = APserver.arg("ssid");
  String newPASS = APserver.arg("pass");

  if (newSSID.length() > 0 && newPASS.length() > 0)
  {
    Serial.println("Successfull input");

    clear_EEPROM();
    write_EEPROM(newSSID, newPASS);
    setup_EEPROM();

    replyPage += "<html><head><meta charset='utf-8'>";
    replyPage += "<meta http-equiv='X-UA-Compatible' content='IE=edge'>";
    replyPage += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
    replyPage += "<meta name='description' content=''>";
    replyPage += "<meta name='author' content=''>";
    replyPage += "<title>Kolonial Klikk</title>";
    replyPage += "<style>";
    replyPage += "div {width:50%; position: relative; margin:auto; padding-top:20%; font-weight:300;}";
    replyPage += "li {padding-left:30px;}";
    replyPage += "a {color: inherit;}";
    replyPage += "</style></head>";
    replyPage += "<body style='font-family: Helvetica, sans-serif; font-weight: 400; font-size: 18px;'>";
    replyPage += "<div><h1>Informasjonen er overført</h1>";
    replyPage += "<p>Knappen vil om 5 sekunder restarte seg selv</p>";
    replyPage += "<p>Om du fortsatt kan se nettverket 'Kolonial Klikk' om 2-3 minutter klarte ikke Kolonial Klikk å koble seg suksessfullt på nettet du valgte</p>";
    replyPage += "<p>Dette kan være på grunn av følgende problemer:";
    replyPage += "<li>Feil passord ble fylt inn</li>";
    replyPage += "<li>Forbindelsen mellom Kolonial Klikk og  din router er for svak - prøv da å flytte Klikk nærmere routeren</li>";
    replyPage += "</p><p>Hvis 'Kolonial Klikk' har forsvunnet fra din liste over nettverk innen 2-3 minutter var koblingen suksessfull og du kan nå begynne å bruke din Kolonial Klikk - ";
    replyPage += "innstillinger for dine Klikk kan du konfiguere på <a ";
    replyPage += "href='http://www.kolonialklikk.no'>www.kolonialklikk.no</a></p>";
    replyPage += "</div><footer><svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 700 700'>";
    replyPage += "<style>.a{fill:#413746;}.b{fill:#FEA500;}</style><polygon points='58 343.4 34.2 343.4 34.2 217.1 58.3 217.1 58.3 278.1 106.2 216.9 135.6 216.9 85.7 281.1 135 343.4 105.6 343.4 58 283.6 ' class='a'/>";
    replyPage += "<path d='M178.9 256.8c-24.6 0-44.5 19.9-44.5 44.5 0 24.6 19.9 44.5 44.5 44.5s44.5-19.9 44.5-44.5C223.4 276.7 203.5 256.8 178.9 256.8zM178.9 325.4c-12.8 0-23.1-10.9-23.1-24.2 0-13.4 10.4-24.2 23.1-24.2 12.8 0 23.1 10.9 23.1 24.2C202 314.6 191.7 325.4 178.9 325.4z' class='a'/>";
    replyPage += "<path d='M326.3 256.8c-24.6 0-44.5 19.9-44.5 44.5 0 24.6 19.9 44.5 44.5 44.5s44.5-19.9 44.5-44.5C370.7 276.7 350.8 256.8 326.3 256.8zM326.3 325.4c-12.8 0-23.1-10.9-23.1-24.2 0-13.4 10.4-24.2 23.1-24.2s23.1 10.9 23.1 24.2C349.4 314.6 339 325.4 326.3 325.4z' class='a'/>";
    replyPage += "<path d='M236.1 217.1h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L236.1 217.1z' class='a'/>";
    replyPage += "<path d='M629.1 217.1h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L629.1 217.1z' class='a'/>";
    replyPage += "<path d='M632 217.1h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L632 217.1z' class='a'/>";
    replyPage += "<path d='M384 258.4h23v7.5c0 0 10.5-9.4 24.1-9.1 0 0 30.7-2.2 31.9 27.4v59.6h-22.4l-0.3-50.3c0 0-0.1-16.6-15.6-16.9 0 0-16 0.5-17.6 15.7l0 51.7h-23.3L384 258.4z' class='a'/>";
    replyPage += "<rect x='482.8' y='258.4' width='23.4' height='85.8' class='a'/>";
    replyPage += "<circle cx='494.4' cy='228.1' r='14.4' class='a'/>";
    replyPage += "<polygon points='59.2 484.4 35.4 484.4 35.4 358.1 59.5 358.1 59.5 419 107.4 357.8 136.8 357.8 86.9 422.1 136.2 484.4 106.9 484.4 59.2 424.6 ' class='a'/>";
    replyPage += "<path d='M144.6 359.9h23.8v103.3c0 0-0.6 2.5 2.8 3h8v20.8h-13.8c0 0-20.2-1.4-20.5-20.5L144.6 359.9z' class='a'/>";
    replyPage += "<rect x='199.6' y='399.4' width='23.4' height='85.8' class='a'/>";
    replyPage += "<circle cx='212.3' cy='369.1' r='14.4' class='a'/>";
    replyPage += "<path d='M592.8 258.4V269c-7.4-7.3-17.4-11.8-28.3-11.8 -23 0-41.6 19.7-41.6 44.1 0 24.3 18.6 44.1 41.6 44.1 11 0 20.9-4.5 28.3-11.8V344h19.5v-85.5H592.8zM567 325.2c-12.6 0-22.9-10.9-22.9-24.3s10.2-24.3 22.9-24.3 22.9 10.9 22.9 24.3S579.7 325.2 567 325.2z' class='a'/>";
    replyPage += "<path d='M565.5 377.2c4-0.3 7.6 1.6 10.9 4.2 8.1 6.4 16.2 12.7 24.2 19.2 2.3 1.8 3.7 1.8 6-0.1 7.9-6.6 16.1-12.9 24.2-19.2 8-6.3 17.9-5.5 23.7 1.9 5.6 7.1 4.2 16.8-3.6 23.1 -14.7 11.8-29.6 23.4-44.4 35.2 -2.1 1.7-3.5 1.8-5.6 0 -15.3-12.2-30.7-24.1-45.9-36.3 -5.3-4.2-7-11.3-4.8-17.7C552.4 381.2 558.1 377.2 565.5 377.2z' class='b'/>";
    replyPage += "<path d='M549 472.6c0-1.9 0-3.9 0-5.8 3.1-9.5 8-13.1 17.8-13.1 24.9 0 49.8 0 74.7 0 7.6 0 13.6 4.2 15.9 10.7 2.2 6.3 0.3 13.2-4.9 17.6 -3 2.6-6.6 3.7-10.5 3.7 -25.7 0-51.4 0.1-77.1 0C556.8 485.7 551.8 481.3 549 472.6z' class='b'/>";
    replyPage += "<polygon points='326.9 484.1 296 443.6 324.5 405.5 297.2 405.2 268.6 440.5 268.6 379.6 268.5 379.6 268.5 446.4 299.1 484.3 ' class='a'/>";
    replyPage += "<polygon points='244.6 358.1 244.6 484.4 268.4 484.4 268.6 424.9 268.6 424.9 268.6 358.1 ' class='a'/>";
    replyPage += "<polygon points='424 484.1 393.1 443.6 421.6 405.5 394.3 405.2 365.7 440.5 365.7 379.6 365.7 379.6 365.7 446.4 396.2 484.3 ' class='a'/>";
    replyPage += "<polygon points='341.7 358.1 341.7 484.4 365.5 484.4 365.7 424.9 365.7 424.9 365.7 358.1 ' class='a'/>";
    replyPage += "<path d='M500.6 364.5c-2.6 4.7-5.3 9.4-7.9 14.2 -0.8 1.5-1.6 3-2.5 4.7 -1.6-0.9-3-1.6-4.6-2.5 3.4-6.3 6.8-12.7 10.3-19C497.5 362.8 499 363.6 500.6 364.5z' class='b'/>";
    replyPage += "<path d='M437.3 413.7c-0.4-1.2-0.8-2.8-1.2-4.1 7-2.1 13.9-4.1 20.9-6.2 0.3 1.1 0.8 2.7 1.1 4.1C451.5 409.5 444.5 411.6 437.3 413.7z' class='b'/>";
    replyPage += "<path d='M494.9 391.9c7-2.1 13.9-4.1 20.8-6.1 0.4 1.4 0.9 3 1.3 4.4 -6.8 2-13.8 4.1-20.9 6.2C495.7 395.1 495.3 393.5 494.9 391.9z' class='b'/>";
    replyPage += "<path d='M464.9 360.6c1.2-0.3 2.7-0.8 4.1-1.2 2 6.8 4 13.6 6.1 20.5 -1.3 0.3-2.9 0.6-4.3 1C469 374.5 467 367.6 464.9 360.6z' class='b'/>";
    replyPage += "<path d='M441.4 382c0.8-1.5 1.5-2.8 2.4-4.3 6.2 3.4 12.5 6.7 18.8 10.2 -0.7 1.4-1.5 2.8-2.4 4.3C454.1 388.8 447.9 385.5 441.4 382z' class='b'/>";
    replyPage += "<path d='M494.3 410.7c0.8-1.5 1.6-2.9 2.4-4.4 6.3 3.4 12.5 6.8 18.9 10.2 -0.8 1.5-1.6 2.9-2.4 4.4C506.9 417.5 500.7 414.1 494.3 410.7z' class='b'/>";
    replyPage += "<path d='M478.9 485.5c-0.1-1-0.3-1.9-0.2-2.6 0.6-4.7-1.3-8.4-4.3-12 -6-7.3-11.6-14.8-17.3-22.4 -1-1.3-1.7-3.1-1.8-4.7 -0.1-1.4 0.6-3.3 1.6-4.2 1.5-1.2 3.7-1.5 5.4 0.1 1.8 1.6 3.6 3.3 5.4 5 1.2 1.1 2.3 2.6 4.2 1.8 1.9-0.8 1.7-2.6 1.6-4.2 -0.3-11.1-0.7-22.1-1-33.2 0-0.6 0-1.1 0-1.7 0.1-3.4 1.3-4.8 4.2-4.9 3-0.1 5.1 1.6 5.3 4.6 0.2 2.8 0.2 5.6 0.3 8.4 0.1 4.3 0.2 8.5 0.4 12.8 0.1 2.7 1 3.5 3.6 3.5 1.3 0 2.6-0.1 3.9-0.1 1.8 0 3.8-0.7 4.3 2.2 0.1 0.6 1.7 1.1 2.7 1.2 1.4 0.2 2.8 0 4.2-0.1 1.9-0.2 3.4-0.1 4.4 2.1 0.3 0.8 2 1.3 3.1 1.4 1.9 0.2 3.8-0.1 5.6-0.1 3.6 0 5.9 2.2 6 5.8 0.2 6.4 0.5 12.8 0.5 19.2 0 1.7-0.8 3.5-1.5 5.1 -2 5-4.1 10-6.3 15 -0.3 0.6-1.3 1.3-2 1.3C500.7 485 490 485.2 478.9 485.5z' class='b'/>";
    replyPage += "</svg></footer>";
    replyPage += "</body></html>";

    SucceededInput = true;

    APserver.send(200, "text/html", replyPage);

    delay(5000);

    Serial.println("Resetting ");
    ESP.restart();
  }
  else
  {
    Serial.println("Failed to fetch input");
    Serial.print("SSID: ");
    Serial.println(newSSID);
    Serial.print("PASS: ");
    Serial.println(newPASS);
    replyPage += "<HTML><HEAD><TITLE>Oida</TITLE>";
    replyPage += "<meta charset='utf-8'>";
    replyPage += "<HEAD><BODY style='background-color:orange;'>";
    replyPage += "<CENTER><h1>Noe gikk galt ..</h1>";
    replyPage += "<a href='root'>Trykk her for å prøve på nytt</a>";
    replyPage += "</CENTER></BODY></HTML>";

    SucceededInput = false;

    APserver.send(200, "text/html", replyPage);
  }
}
