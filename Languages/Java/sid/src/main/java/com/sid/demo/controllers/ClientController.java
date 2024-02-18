package com.sid.demo.controllers;

import com.sid.demo.models.Client;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/client")
public class ClientController {
    @GetMapping
    public Client receive() {
        return new Client(1, "Maurício");
    }
}
