//
//  Profile_Main.swift
//  Simple
//
//  Created by Clement Chan on 9/19/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation
import UIKit

class Profile_Main : UIViewController{

    @IBOutlet weak var User_ID: UILabel!
    @IBOutlet weak var Time_Greetings: UILabel!
    @IBOutlet weak var user_greetings: UILabel!
    @IBOutlet weak var Bkground_Image: UIImageView!
    
    //Getting Profile name from the server
    
    @IBOutlet weak var Profile_Name: UILabel!
    
    @IBAction func Single_Meet(sender: AnyObject) {
        
        loadDestinationVC();
        
    }
    
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
        
        let manager = AFHTTPRequestOperationManager()
        
        var params = [
            "username":login.loginid
        ]
        
        manager.POST("http://localhost:3000/user",
            parameters: params,
            
            //what is needed for success to execute?
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("successfully retrieve user's info")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
    }
    
    
    //To Logout and delete token that is assigned
    @IBAction func Logout(sender: AnyObject) {
        
        //println(loginUsername.text)
        let manager = AFHTTPRequestOperationManager()
        
        var params = [
            
            "username":login.loginid,
            "password":login.password
            
        ]
        
        let defaults = NSUserDefaults.standardUserDefaults()
        defaults.setObject(nil, forKey: "token")
        //defaults.getObject(for
        defaults.synchronize()
        
        
        manager.POST("http://localhost:3000/logout",
            parameters: params,
            
            //what is needed for success to execute?
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("successful logout")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }
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
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("To_Meet", sender: nil)
    }
    
    
    
};