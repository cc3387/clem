//
//  Meet_Profile.swift
//  Simple
//
//  Created by Clement Chan on 10/11/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//


import Foundation
import UIKit

class Profile_Meet_Main : UIViewController{
    
    @IBOutlet weak var User_ID: UILabel!
    @IBOutlet weak var Time_Greetings: UILabel!
    @IBOutlet weak var user_greetings: UILabel!
    @IBOutlet weak var Bkground_Image: UIImageView!
    
    //Getting Profile name from the server
    @IBOutlet weak var Profile_Name: UILabel!
    
    //Matching Labels
    @IBOutlet weak var First_Match: UILabel!
    @IBOutlet weak var First_Loc: UILabel!
    @IBOutlet weak var First_Uni: UILabel!
    @IBOutlet weak var First_Major: UILabel!
    
    @IBOutlet weak var Second_Match: UILabel!
    @IBOutlet weak var Second_Loc: UILabel!
    @IBOutlet weak var Second_Uni: UILabel!
    @IBOutlet weak var Second_Major: UILabel!
    
    @IBOutlet weak var Third_Match: UILabel!
    @IBOutlet weak var Third_Loc: UILabel!
    @IBOutlet weak var Third_Uni: UILabel!
    @IBOutlet weak var Third_Major: UILabel!
    
    @IBOutlet weak var Fourth_Match: UILabel!
    @IBOutlet weak var Fourth_Loc: UILabel!
    @IBOutlet weak var Fourth_Uni: UILabel!
    @IBOutlet weak var Fourth_Major: UILabel!
    
    @IBOutlet weak var Fifth_Match: UILabel!
    
    //Getting the login_user id that is collected from the login page
    var loginuser: String = login.loginid;
    var user1: String = "";
    
    override func viewDidLoad() {
        
        let hours = hour();
        let minutes = minute();
        let hour_i = hour_int();
        let minute_i = minute_Int();
        
        if(hour_i > 6 && hour_i < 12){
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Morning, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Morning, the time is " + hours + " : " + minutes;
            }
            
            Time_Greetings.textColor = UIColor.blackColor();
            Bkground_Image.image = UIImage(named: "malaysia_morning.jpg");
            
            //Setting the User ID to login user id
            self.User_ID.text = "Welcome to Simple, " + self.loginuser;
            self.User_ID.textColor = UIColor.blackColor();
        }
        else if(hour_i >= 12 && hour_i <= 18){
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Afternoon, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Afternoon, the time is " + hours + " : " + minutes;
            }
            
            let random = arc4random_uniform(2);
            
            if(random == 0){
                Bkground_Image.image = UIImage(named: "chicago_afternoon.jpg");
            }
            
            if(random == 1){
                Bkground_Image.image = UIImage(named: "Sunset.jpg");
            }
            
            //Setting the User ID to login user id
            self.User_ID.text = "Welcome to Simple, " + self.loginuser;
            self.User_ID.textColor = UIColor.blackColor();
        }
        else{
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + minutes;
            }
            
            
            let random = arc4random_uniform(3);
            
            if(random == 0){
                Bkground_Image.image = UIImage(named: "night_sky.jpg");
            }
            else if(random == 1){
                Bkground_Image.image = UIImage(named: "hongkongnight.jpg");
            }
            else if(random == 2){
                Bkground_Image.image = UIImage(named: "Paris_Night.jpg");
            }
            
            //Setting the User ID to login user id
            self.User_ID.text = "Welcome to Simple, " + self.loginuser;
            self.User_ID.textColor = UIColor.whiteColor();
        }
        
        //Getting the matched information from the server
        let manager = AFHTTPRequestOperationManager()
        
        manager.GET("http://localhost:3000/Matching",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                println("JSON: " + responseObject.description)
                println("Object obtained successfully");
                println(responseObject.count);
                
                if(responseObject.count > 0){
                
                if(responseObject.count > 0){
                //Taking the information of the first object
                if let results = responseObject[0] as? NSDictionary {
                    
                    if let Profile_Name = results["Profile_Name"] as? String {
                        self.First_Match.text = Profile_Name as String
                        if(self.hour_int() > 18){
                        self.First_Match.backgroundColor = UIColor.grayColor();
                        }
                        else{
                        self.First_Match.textColor = UIColor.redColor();
                        }
                        //self.First_Match.adjustsFontSizeToFitWidth = true
                        
                        if let Profile_Loc = results["location"] as? String {
                            self.First_Loc.text = Profile_Loc as String
                            if(self.hour_int() > 18){
                            self.First_Loc.backgroundColor = UIColor.grayColor();
                            }else{
                            self.First_Loc.textColor = UIColor.redColor();
                            }
                            //self.First_Loc.adjustsFontSizeToFitWidth = true
                            
                            if let Profile_Edu = results["Education"] as? String {
                                self.First_Uni.text = Profile_Edu as String
                                if(self.hour_int() > 18){
                                self.First_Uni.backgroundColor = UIColor.grayColor();
                                }
                                else{
                                self.First_Uni.textColor = UIColor.redColor();
                                }
                                //self.First_Uni.adjustsFontSizeToFitWidth = true
                                
                                if let Profile_Major = results["Major"] as? String {
                                    self.First_Major.text = Profile_Major as String
                                    if(self.hour_int() > 18){
                                    self.First_Major.backgroundColor = UIColor.grayColor();
                                    }
                                    else{
                                    self.First_Major.textColor = UIColor.redColor();
                                    }
                                    //self.First_Major.adjustsFontSizeToFitWidth = true
                                }
                            }
                        }
                    }
                }
                }else{self.First_Match.textColor = UIColor.clearColor();
                      self.First_Loc.textColor = UIColor.clearColor();
                      self.First_Uni.textColor = UIColor.clearColor();
                      self.First_Major.textColor = UIColor.clearColor();}
                
                //Taking the information of the second object
                if(responseObject.count > 1){
                if let results = responseObject[1] as? NSDictionary {
                        if let Profile_Name = results["Profile_Name"] as? String {
                            self.Second_Match.text = Profile_Name as String
                            if(self.hour_int() > 18){
                            self.Second_Match.backgroundColor = UIColor.grayColor();
                            }
                            else{
                            self.Second_Match.textColor = UIColor.redColor();
                            }
                            //self.Second_Match.adjustsFontSizeToFitWidth = true
                        if let Profile_Loc = results["location"] as? String {
                                self.Second_Loc.text = Profile_Loc as String
                                if(self.hour_int() > 18){
                                self.Second_Loc.backgroundColor = UIColor.grayColor();
                                }
                                else{
                                self.Second_Loc.textColor = UIColor.redColor();
                                }
                                //self.Second_Match.adjustsFontSizeToFitWidth = true
                            if let Profile_Uni = results["Education"] as? String {
                                self.Second_Uni.text = Profile_Uni as String
                                if(self.hour_int() > 18){
                                    self.Second_Uni.backgroundColor = UIColor.grayColor();
                                }
                                else{
                                    self.Second_Uni.textColor = UIColor.redColor();
                                }
                                //self.Second_Match.adjustsFontSizeToFitWidth = true
                                if let Profile_Major = results["Major"] as? String {
                                    self.Second_Major.text = Profile_Major as String
                                    if(self.hour_int() > 18){
                                        self.Second_Major.backgroundColor = UIColor.grayColor();
                                    }
                                    else{
                                        self.Second_Major.textColor = UIColor.redColor();
                                    }
                                    //self.Second_Match.adjustsFontSizeToFitWidth = true
                                }
                            }
                        }
                    }
                }
                }else{self.Second_Match.textColor = UIColor.clearColor();
                      self.Second_Loc.textColor = UIColor.clearColor();
                      self.Second_Uni.textColor = UIColor.clearColor();
                      self.Second_Major.textColor = UIColor.clearColor();}
                
                //Taking the information of the third object
                if(responseObject.count > 2){
                if let results = responseObject[2] as? NSDictionary {
                        if let Profile_Name = results["Profile_Name"] as? String {
                            self.Third_Match.text = Profile_Name as String
                            if(self.hour_int() > 18){
                                self.Third_Match.backgroundColor = UIColor.grayColor();
                            }
                            else{
                                self.Third_Match.textColor = UIColor.redColor();
                            }
                            
                            //self.Third_Match.backgroundColor = UIColor.grayColor();
                            //self.Third_Match.adjustsFontSizeToFitWidth = true
                            
                            if let Profile_Loc = results["location"] as? String {
                                self.Third_Loc.text = Profile_Loc as String
                                if(self.hour_int() > 18){
                                    self.Third_Loc.backgroundColor = UIColor.grayColor();
                                }
                                else{
                                    self.Third_Loc.textColor = UIColor.redColor();
                                }
                                //self.Third_Match.backgroundColor = UIColor.grayColor();
                                //self.Third_Match.adjustsFontSizeToFitWidth = true
                                
                                if let Profile_Uni = results["Education"] as? String {
                                    self.Third_Uni.text = Profile_Uni as String
                                    if(self.hour_int() > 18){
                                        self.Third_Uni.backgroundColor = UIColor.grayColor();
                                    }
                                    else{
                                        self.Third_Uni.textColor = UIColor.redColor();
                                    }
                                    //self.Third_Match.backgroundColor = UIColor.grayColor();
                                    //self.Third_Match.adjustsFontSizeToFitWidth = true
                                    
                                    if let Profile_Major = results["Major"] as? String {
                                        self.Third_Major.text = Profile_Major as String
                                        if(self.hour_int() > 18){
                                            self.Third_Major.backgroundColor = UIColor.grayColor();
                                        }
                                        else{
                                            self.Third_Major.textColor = UIColor.redColor();
                                        }
                                        //self.Third_Match.backgroundColor = UIColor.grayColor();
                                        //self.Third_Match.adjustsFontSizeToFitWidth = true
                                        
                                    }
                                }
                            }
                        }
                    }
                }else{self.Third_Match.textColor = UIColor.clearColor();
                      self.Third_Loc.textColor = UIColor.clearColor();
                      self.Third_Uni.textColor = UIColor.clearColor();
                      self.Third_Major.textColor = UIColor.clearColor();}
                    
                //Taking the information of the fourth object
                if(responseObject.count > 3){
                if let results = responseObject[3] as? NSDictionary {
                        if let Profile_Name = results["Profile_Name"] as? String {
                            self.Fourth_Match.text = Profile_Name as String
                            if(self.hour_int() > 18){
                                self.Fourth_Match.backgroundColor = UIColor.grayColor();
                            }
                            else{
                                self.Fourth_Match.textColor = UIColor.redColor();
                            }
                            //self.Fourth_Match.backgroundColor = UIColor.grayColor();
                            //self.Fourth_Match.adjustsFontSizeToFitWidth = true
                            if let Profile_Loc = results["location"] as? String {
                                self.Fourth_Loc.text = Profile_Loc as String
                                if(self.hour_int() > 18){
                                    self.Fourth_Loc.backgroundColor = UIColor.grayColor();
                                }
                                else{
                                    self.Fourth_Loc.textColor = UIColor.redColor();
                                }
                                //self.Fourth_Match.backgroundColor = UIColor.grayColor();
                                //self.Fourth_Match.adjustsFontSizeToFitWidth = true
                                if let Profile_Uni = results["Education"] as? String {
                                    self.Fourth_Uni.text = Profile_Uni as String
                                    if(self.hour_int() > 18){
                                        self.Fourth_Uni.backgroundColor = UIColor.grayColor();
                                    }
                                    else{
                                        self.Fourth_Uni.textColor = UIColor.redColor();
                                    }
                                    //self.Fourth_Match.backgroundColor = UIColor.grayColor();
                                    //self.Fourth_Match.adjustsFontSizeToFitWidth = true
                                    if let Profile_Major = results["Major"] as? String {
                                        self.Fourth_Major.text = Profile_Major as String
                                        if(self.hour_int() > 18){
                                            self.Fourth_Major.backgroundColor = UIColor.grayColor();
                                        }
                                        else{
                                            self.Fourth_Major.textColor = UIColor.redColor();
                                        }
                                        //self.Fourth_Match.backgroundColor = UIColor.grayColor();
                                        //self.Fourth_Match.adjustsFontSizeToFitWidth = true
                                    }
                                }
                            }
                        }
                  }
                }else{self.Fourth_Match.textColor = UIColor.clearColor();
                      self.Fourth_Loc.textColor = UIColor.clearColor();
                      self.Fourth_Uni.textColor = UIColor.clearColor();
                      self.Fourth_Major.textColor = UIColor.clearColor();}
                    
                //Taking the information of the fifth object
                /*if(responseObject.count > 4){
                    if let results = responseObject[4] as? NSDictionary {
                            if let Profile_Name = results["Profile_Name"] as? String {
                                self.Fifth_Match.text = Profile_Name as String
                                //self.Fourth_Match.backgroundColor = UIColor.grayColor();
                                self.Fifth_Match.adjustsFontSizeToFitWidth = true
                            }
                        }
                }else{self.Fifth_Match.textColor = UIColor.clearColor();}*/
                    
                    
                    
              }else{
              println("There is no response found")
              self.First_Match.textColor = UIColor.clearColor();
              self.Second_Match.textColor = UIColor.clearColor();
              self.Third_Match.textColor = UIColor.clearColor();
              self.Fourth_Match.textColor = UIColor.clearColor();
             }
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                println("Error: " + error.localizedDescription)
            }
        )
        
        
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    
    //Functions that will be used to display the time
    func hour() -> String
    {
        //Get Hour
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var hours = components.hour
        let hour = String(hours);
        //Return Hour
        return hour
    }
    
    func hour_int() -> Int
    {
        //Get Hour
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var hours = components.hour
        let hour = Int(hours);
        //Return Hour
        return hour
    }
    
    
    func minute() -> String
    {
        //Get Minute
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var minutes = components.minute
        let minute = String(minutes);
        //Return Minute
        return minute
    }
    
    func minute_Int() -> Int
    {
        //Get Minute
        var date:NSDate = NSDate();
        var calendar: NSCalendar = NSCalendar.currentCalendar();
        var components:NSDateComponents = calendar.components(
            NSCalendarUnit.CalendarUnitHour | NSCalendarUnit.CalendarUnitMinute | NSCalendarUnit.CalendarUnitSecond, fromDate: date)
        var minutes = components.minute
        let minute = Int(minutes);
        //Return Minute
        return minute
    }
    
};