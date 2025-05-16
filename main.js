const endpoint = "https://7bb1-2001-448a-2082-80f8-34f4-ad6b-b86a-6157.ngrok-free.app";

function getDapurLed() {
  fetch(endpoint + "/dapur", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledDapur.style.backgroundColor = "blue";
        dapurLedImage.src = "assets/led-on.png";
      } else {
        ledDapur.style.backgroundColor = "#579fff";
        dapurLedImage.src = "assets/led-off.png";
      }
    });
}

function getTamuLed() {
  fetch(endpoint + "/tamu", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledTamu.style.backgroundColor = "blue";
        tamuLedImage.src = "assets/led-on.png";
      } else {
        ledTamu.style.backgroundColor = "#579fff";
        tamuLedImage.src = "assets/led-off.png";
      }
    });
}

function getMakanLed() {
  fetch(endpoint + "/makan", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledMakan.style.backgroundColor = "blue";
        makanLedImage.src = "assets/led-on.png";
      } else {
        ledMakan.style.backgroundColor = "#579fff";
        makanLedImage.src = "assets/led-off.png";
      }
    });
}

function getToiletLed() {
  fetch(endpoint + "/toilet", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledToilet.style.backgroundColor = "blue";
        toiletLedImage.src = "assets/led-on.png";
      } else {
        ledToilet.style.backgroundColor = "#579fff";
        toiletLedImage.src = "assets/led-off.png";
      }
    });
}

function getHalamanLed() {
  fetch(endpoint + "/halaman", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledHalaman.style.backgroundColor = "blue";
        halamanLedImage.src = "assets/led-on.png";
      } else {
        ledHalaman.style.backgroundColor = "#579fff";
        halamanLedImage.src = "assets/led-off.png";
      }
    });
}

function setDapurLed() {
  fetch(endpoint + "/dapur", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

function setTamuLed() {
  fetch(endpoint + "/tamu", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

function setMakanLed() {
  fetch(endpoint + "/makan", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

function setToiletLed() {
  fetch(endpoint + "/toilet", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

function setHalamanLed() {
  fetch(endpoint + "/halaman", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload());
}

getDapurLed();
getTamuLed();
getMakanLed();
getToiletLed();
getHalamanLed();
