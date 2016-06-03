//
//  ViewControllerLogin.swift
//  Dating_App
//
//  Created by Clement Chan on 7/11/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit
import Firebase

class ViewControllerLogin: UIViewController {
    
    @IBOutlet weak var Username: UITextField!
    @IBOutlet weak var Password: UITextField!
    
    var user: String = "";
    var decision_user: Int = 0
    var decision_pwd: Int = 0
    var user1:User!
    var count: Int = 0;
    var ref: Firebase!
    
    override func viewDidLoad() {

    }
    
    /*override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }*/

    /*override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "Main_Profile" {
            if let destinationVC = segue.destinationViewController as? Main_Profile{
                destinationVC.loginuser = Username.text;
            }
        }
    }*/
    
    @IBAction func Login(sender: AnyObject) {
        
        var ref = Firebase(url:"https://simpleplus.firebaseio.com")
        
        ref.authUser(self.Username.text, password: self.Password.text) {
            error, authData in
            if error != nil {
                // an error occured while attempting login
                println("Login info is wrong");
            } else {
                // user is logged in, check authData for data
                login.loginid = self.Username.text;
                login.password = self.Password.text;
                self.Password.text = "**********";
                login.chatid = ref.authData.uid
                println(login.chatid)
                self.loadDestinationVC();
            }
        }
        
        //Login with our own register
        /*let manager = AFHTTPRequestOperationManager()
        
        var params = [
            
            "username":Username.text,
            "password":Password.text
            
        ]
        
        manager.POST("http://localhost:3000/login1",
            parameters: params,
            
            //what is needed for success to execute?
            success: { (AFHTTPRequestOperation, userObject) -> Void in
                println(userObject)
                if let results = userObject as? NSDictionary {
                    if let user_details = results["user"] as? NSDictionary {
                        if let username = user_details["username"] as? String {
                            self.user1 = User(username: username, token: "helloworld")
                            let defaults = NSUserDefaults.standardUserDefaults()
                            defaults.setObject(self.user1.token, forKey: "token")
                            defaults.synchronize()
                            self.performSegueWithIdentifier("openProfile", sender: self)
                            
                        }
                        
                    }
                }
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail in sending")
        }*/
    }
    
    //Load destination to the main profile
    func loadDestinationVC(){
    self.performSegueWithIdentifier("openProfile", sender: nil)
    }

    
    /*func finduserid(){
        var query = PFQuery(className: "UserDetails");
        query.includeKey(self.Username.text);
        query.whereKey("username", equalTo: self.Username.text);
        query.findObjectsInBackgroundWithBlock {
            (objects: [AnyObject]?, error: NSError?) -> Void in
            if objects!.count == 0 {
                self.decision_user = 0;
            }
            else {
                self.decision_user = 1;
                // The find succeeded.
                //println("Successfully retrieved \(objects!.count) record.")
                // Do something with the found objects
                if let objects = objects as? [PFObject] {
                    for object in objects {
                        //println("Username_ID is: ");
                        println(object.objectId);
                    }
                }
            }
        }
    }*/
    
    /*func move(){
    func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        counter++;
        if segue.identifier == "Main_Profile" {
            if let destinationVC = segue.destinationViewController as? Main_Profile{
                destinationVC.loginuser = counter
            }
          }
        }
    }*/
    
    
    //This part retrieve the Username saved that were passed on after clicking the "Login" button
    /*func RetrieveUsername(){
        let usertext = Username.text;
        //Creating a new PFQuery
        var query = PFQuery(className: "User")
        query.whereKey("username", equalTo: usertext)
        //Call FindObjectsinBackground
        query.findObjectsInBackgroundWithBlock {
            (objects: [AnyObject]?, error: NSError?) -> Void in
            if objects!.count == 0 {
                self.decision_user = 0;
            }
            else {
                self.decision_user = 1;
                // The find succeeded.
                //println("Successfully retrieved \(objects!.count) record.")
                // Do something with the found objects
                if let objects = objects as? [PFObject] {
                    for object in objects {
                        //println("Username_ID is: ");
                        println(object.objectId)
                    }
                }
            }
        }
    }*/
    

    //This part retrieve the Password saved that were passed on after clicking the "Login" button
    /*func RetrievePassword(){
        
        let passwordtext = Password.text;
        //Creating a new PFQuery
        var query = PFQuery(className: "User")
        query.whereKey("password", equalTo: passwordtext)
        //Call FindObjectsinBackground
        query.findObjectsInBackgroundWithBlock{
            (objects:[AnyObject]?, error: NSError?) -> Void in
            
            if objects!.count == 0{
            self.decision_pwd = 0;
            }
            else {
                self.decision_pwd = 1;
                // The find succeeded.
                //println("Successfully retrieved \(objects!.count) record.")
                // Do something with the found objects
                if let objects = objects as? [PFObject] {
                    for object in objects {
                        //println("Password ID is: ")
                        println(object.objectId)
                  }
               }
            }
        }
    }*/
    
    
    //if login fails how do I redirect back?
    /*override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if(segue.identifier == "openProfile") {
            //self.user = User(username: "hsuregan5")
            let newViewController = segue.destinationViewController as! Profile_Main
            //println("YAY::")
            println(self.user1.username)
            newViewController.user1 = self.user
            
        }
    }*/
    
}

//Storing the userid as global variable in the ios app machine
struct login{
    
    static var loginid = "";
    static var password = "";
    static var chatid = "";
    
}

struct arrays{
    
    static var friendsArray:[String] = [String]() //Set an empty array for friend names
    static var friendlocArray:[String] = [String]() //Set an empty array for friend locations
    static var frienduniArray:[String] = [String]() //Set an empty array for university locations
    static var friendmajorArray:[String] = [String]() //Set an empty array for major locations
    static var friendidArray:[String] = [String]() //Set an empty array for friend's ID
    static var chatcheck:[Int] = [Int]() //Check 1:1 relationship
    
};
