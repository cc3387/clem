//
//  Main_Profile.swift
//  Dating_App
//
//  Created by Clement Chan on 7/19/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit

class Main_Profile: UIViewController{
    
    @IBOutlet weak var Hour: UILabel!
    @IBOutlet weak var Minutes: UILabel!
    @IBOutlet weak var username: UILabel!
    @IBOutlet weak var Greetings: UILabel!
    
    var loginuser: String = login_info.user_id

    override func viewDidLoad() {
        let hours = hour();
        let minutes = minute();
        let hour_i = hour_int();
        let minute_i = minute_Int();
        
        if(hour_i > 6 && hour_i < 12){
        self.Greetings.text = "Good Morning, "
        }
        else if(hour_i >= 12 && hour_i <= 18){
        self.Greetings.text = "Good Afternoon, "
        }
        else{
        self.Greetings.text = "Good Evening, "
        }
        
        self.Hour.text = hours;
        self.Minutes.text = minutes;
        self.username.text = loginuser;
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    
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
    
    
    /*    func toShortTimeString() -> String
    {
    //Get Short Time String
    let formatter = NSDateFormatter()
    formatter.timeStyle = .ShortStyle
    let timeString = formatter.stringFromDate(self)
    
    //Return Short Time String
    return timeString
    }
    */
    
    
    //func loadDestinationVC(){
    //    self.performSegueWithIdentifier("Starting_Storyboard", sender: nil)
    //}
    
}


