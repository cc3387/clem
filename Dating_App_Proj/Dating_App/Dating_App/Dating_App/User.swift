//
//  User.swift
//  datingClient
//
//  Created by Regan Hsu on 10/2/15.
//  Copyright (c) 2015 Regan Hsu. All rights reserved.
//

import Foundation

class User {
    
    var username:String!
    
    init(username:String, token: String) {
        self.username = username
        self.token = token
    }
    //if token is expired, logout
    //if token is not expired, stay logged in
    //everytime viewDidLoad check
    var token:String!
    
    //people you match with
    //var matches = [String:User]()
}