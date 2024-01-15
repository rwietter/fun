package com.sid.net;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;

public class Response {
  public static void sendResponse(OutputStream out, String statusLine, String responseBody) throws IOException {
    PrintWriter writer = new PrintWriter(out, true);
    writer.println(statusLine);
    writer.println("Content-Type: text/plain");
    writer.println("Content-Length: " + responseBody.length());
    writer.println();
    writer.println(responseBody);
    writer.close();
  }
}
