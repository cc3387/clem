//
//  ViewControllerLogin.swift
//  Dating_App
//
//  Created by Clement Chan on 7/11/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit

class ViewControllerLogin: UIViewController {
    
    @IBOutlet weak var Username: UITextField!
    @IBOutlet weak var Password: UITextField!
    
    var decision_user: Int = 0
    var decision_pwd: Int = 0
    //var counter = 0;
    
    
    /*override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }*/

    
    @IBAction func Login(sender: AnyObject) {
        RetrieveUsername();
        RetrievePassword();
        
        if(self.decision_user == 1 && self.decision_pwd == 1){
            self.Username.enabled = false;
            self.Password.enabled = false;
            self.Username.text = "";
            self.Password.text = "";
            //move();
            loadDestinationVC();
        }
    }
    
    func loadDestinationVC(){
    self.performSegueWithIdentifier("Main_Profile", sender: nil)
    }
    
    /*func move(){
    func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        counter++;
        if segue.identifier == "Main_Profile" {
            if let destinationVC = segue.destinationViewController as? Main_Profile{
                destinationVC.numberToDisplay = counter
            }
          }
        }
    }*/
    
    
    //This part retrieve the Username saved that were passed on after clicking the "Login" button
    func RetrieveUsername(){
        
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
    }
    
    //This part retrieve the Password saved that were passed on after clicking the "Login" button
    func RetrievePassword(){
        
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
    }
}