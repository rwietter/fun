package com.sid.net;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;

public class HandleRequest {
  private Response response;

  public HandleRequest(Response response) {
    this.response = response;
  }

  public void handle(Socket clientSocket) {
    try {
      BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
      OutputStream out = clientSocket.getOutputStream();

      String requestLine = in.readLine();
      if (requestLine != null) {
        String[] requestParts = requestLine.split(" ");
        if (requestParts.length >= 2) {
          String method = requestParts[0];
          String path = requestParts[1];

          if (method.equals("GET")) {
            if (path.equals("/")) {
              this.response.sendResponse(out, "HTTP/1.1 200 OK", "Hello!");
            } else {
              this.response.sendResponse(out, "HTTP/1.1 404 Not Found", "404 Not Found");
            }
          }
        }
      }

      clientSocket.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
