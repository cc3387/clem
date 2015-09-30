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
    
    //Getting the login_user id that is collected from the login page
    var loginuser: String = login_info.user_id;
    
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
            self.User_ID.text = "Welcome to Simple, " + loginuser;
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
            self.User_ID.text = "Welcome to Simple, " + loginuser;
            self.User_ID.textColor = UIColor.blackColor();
        }
        else{
            
            if(minute_i < 10){
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + "0" + minutes;
            }
            else{
                self.Time_Greetings.text = "Good Evening, the time is " + hours + " : " + minutes;
            }
            
            
            let random = arc4random_uniform(2);
            
            if(random == 0){
            Bkground_Image.image = UIImage(named: "night_sky.jpg");
            }
            
            if(random == 1){
            Bkground_Image.image = UIImage(named: "hong_kong_night.jpg");
            }
                
                
            //Setting the User ID to login user id
            self.User_ID.text = "Welcome to Simple, " + loginuser;
            self.User_ID.textColor = UIColor.whiteColor();
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
};