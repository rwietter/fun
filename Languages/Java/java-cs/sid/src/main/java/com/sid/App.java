package com.sid;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;

// fonte: https://gist.github.com/k8nx/3314522
public class App {
	static class StatusHandler implements HttpHandler {
		public void handle(HttpExchange exchange) throws IOException {
			exchange.getResponseHeaders().set("Custom-Header-1", "A~HA");
			exchange.sendResponseHeaders(200, "OK\n".length());
			OutputStream os = exchange.getResponseBody();
			os.write("OK\n".getBytes());
			os.flush();
			os.close();
			exchange.close();
		}
	}

	static class PostHandler implements HttpHandler {
		public void handle(HttpExchange exchange) throws IOException {
			switch (exchange.getRequestMethod()) {
			case "POST":
				// Process the POST request here
				String response = "POST request processed.";
				exchange.sendResponseHeaders(200, response.length());
				OutputStream os = exchange.getResponseBody();
				os.write(response.getBytes());
				os.flush();
				os.close();
				break;

				case "GET":
					// Process the POST request here
					String response1 = "GET request processed.";
					exchange.sendResponseHeaders(200, response1.length());
					OutputStream os1 = exchange.getResponseBody();
					os1.write(response1.getBytes());
					os1.flush();
					os1.close();
					break;

				default:
					// Method not allowed for this handler
					String response2 = "Method not allowed.";
					exchange.sendResponseHeaders(405, response2.length());
					OutputStream os2 = exchange.getResponseBody();
					os2.write(response2.getBytes());
					os2.flush();
					os2.close();
					break;
			}
			exchange.close();
		}
	}

	public static void main(String[] args) throws IOException {
		int port = 8080;

		HttpServer server = HttpServer.create(new InetSocketAddress(port), 1024);

		server.createContext("/status", new StatusHandler());
		server.createContext("/post", new PostHandler());

		server.start();
	}
}
