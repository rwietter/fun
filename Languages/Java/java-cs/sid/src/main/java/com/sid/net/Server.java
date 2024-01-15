package com.sid.net;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
  private HandleRequest handleRequest;

  public Server(HandleRequest handleRequest) {
    this.handleRequest = handleRequest;
  }


  public void createServer() {
    int port = 8080;

    try (ServerSocket serverSocket = new ServerSocket(port)) {
      System.out.println("Servidor inicializado na porta " + port);

      while (true) {
        try (Socket clientSocket = serverSocket.accept()) {
          this.handleRequest.handle(clientSocket);
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
