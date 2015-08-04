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
    @IBOutlet weak var myNameLabel: UILabel!
    @IBOutlet weak var Address: UILabel!
    @IBOutlet weak var Gender: UILabel!
    @IBOutlet weak var login: UILabel!
    @IBOutlet weak var Name: UILabel!
    
    

    
    var loginuser: String = login_info.user_id
    
    @IBAction func Posting(sender: AnyObject) {
        
        var params = [
            "title":"Clement"
        ]
        
        var ugh = [
            "_id": "55c019d23cda349c02b6f974"
            
        ]
        
        let manager = AFHTTPRequestOperationManager()
        /*manager.POST("http://samwize.com/api/poo/", parameters: params,
            
            success: {(operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                println(responseObject)
            },
            
            failure: {(operation: AFHTTPRequestOperation!,error: NSError!) in
                println("uuuError: " + error.localizedDescription)
        })
        
        //post to your node server
        manager.POST("http://localhost:3000/items",
            parameters: params,
            success: { (AFHTTPRequestOperation, AnyObject) -> Void in
                println("success!")
            }) { (AFHTTPRequestOperation, NSError) -> Void in
                println("fail")
        }*/
        
        //Get information in your server
        manager.GET( "http://localhost:3000/items/person",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                println("JSON: " + responseObject.description)
                if let results = responseObject["person"] as? NSArray {
                    if let title = results[0] as? String {
                        self.Name.text = title as String
                        self.Name.adjustsFontSizeToFitWidth = true
                }
              }
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                println("Error: " + error.localizedDescription)
        })
    }
    
    /*@IBAction func Posting(sender: AnyObject) {
        
        let manager = AFHTTPRequestOperationManager()
        manager.POST("http://samwize.com/api/poo/", parameters: nil,
            
            success: {(operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                println(responseObject)
            },
            
            failure: {(operation: AFHTTPRequestOperation!,error: NSError!) in
                println("uuuError: " + error.localizedDescription)
        })
    }*/
    
    
    @IBAction func Retrieve(sender: AnyObject) {
    
        // Do any additional setup after loading the view, typically from a nib.
        let manager = AFHTTPRequestOperationManager()
        //let manageraddress = AFHTTPRequestOperationManager()
        self.myNameLabel.text = ""
        
        //create gray activity indicator view
        var activityIndicatorView = UIActivityIndicatorView(activityIndicatorStyle: .Gray)
        
        //add the activity to the viewcontroller's view
        view.addSubview(activityIndicatorView)
        
        //position the activity indicator view in the center
        activityIndicatorView.center = view.center
        
        activityIndicatorView.startAnimating()
        
        manager.GET( "http://api.randomuser.me/",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                
                println("Response: " + responseObject.description)
            
                
                if let results = responseObject["results"] as? NSArray {
                    if let user = results[0] as? NSDictionary {
                        if let user = user["user"] as? NSDictionary {
                            if let name = user["name"] as? NSDictionary {
                                if let first = name["first"] as? String {
                                    var fullName:String = first as String
                                    if let second = name["last"] as? String {
                                        fullName += " "
                                        fullName += second
                                        self.myNameLabel.text = fullName
                                        //self.myNameLabel.adjustsFontSizeToFitWidth = true
                                    }
                                }
                            }
                            
                            if let gender = user["gender"] as? String{
                                self.Gender.text = gender;
                            }
                            
                            if let uname = user["username"] as? String{
                                self.login.text = uname;
                            }
                            
                            if let location = user["location"] as? NSDictionary{
                                if let street = location["street"] as? String {
                                    if let city = location["city"] as? String {
                                        if let state = location["state"] as? String {
                                            if let zip = location["zip"] as? String {
                                                var fulladdress:String = street as String
                                                fulladdress += " "
                                                fulladdress += city
                                                self.Address.text = fulladdress;
                                                //self.Address.adjustsFontSizeToFitWidth = true
                                                //println(fulladdress);
                                            }
                                        }
                                    }
                                }
                            }
                    }
                    else {
                            println(user)
                            self.myNameLabel.text = "failed at cell"
                            self.myNameLabel.adjustsFontSizeToFitWidth = true
                        }
                    }
                    else {
                        self.myNameLabel.text = "failed at user"
                    }
                }
                else {
                    self.myNameLabel.text = "failed at results"
                    self.Address.text = "failed at results"
                }
                activityIndicatorView.stopAnimating()
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                println("uuuError: " + error.localizedDescription)
                //google timeout
                activityIndicatorView.stopAnimating()
                //self.myNameLabel.text = ":("
                
                var alert = UIAlertController(title: "Alert", message: "Message", preferredStyle: UIAlertControllerStyle.Alert)
                alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.Default, handler: nil))
                self.presentViewController(alert, animated: true, completion: nil)
        })
        
        //Get the Address
        /*manageraddress.GET( "http://api.randomuser.me/",
            parameters: nil,
            success: { (operation: AFHTTPRequestOperation!,responseObject: AnyObject!) in
                
                println("Response: " + responseObject.description)
                if let results = responseObject["results"] as? NSArray {
                    if let user = results[0] as? NSDictionary {
                        if let user = user["user"] as? NSDictionary {
                            if let name = user["name"] as? NSDictionary {
                                if let first = name["first"] as? String {
                                    var fullName:String = first as String
                                    if let second = name["last"] as? String {
                                        fullName += " "
                                        fullName += second
                                        self.Address.text = fullName
                                        self.Address.adjustsFontSizeToFitWidth = true
                                    }
                                }
                            }
                        }
                        else {
                            println(user)
                            self.myNameLabel.text = "failed at cell"
                            self.myNameLabel.adjustsFontSizeToFitWidth = true
                            self.Address.text = "failed at cell"
                            self.Address.adjustsFontSizeToFitWidth = true
                        }
                    }
                    else {
                        self.myNameLabel.text = "failed at user"
                        self.Address.text = "failed at user"
                    }
                    //self.myNameLabel.text = nationality
                }
                else {
                    self.myNameLabel.text = "failed at results"
                    self.Address.text = "failed at results"
                }
                activityIndicatorView.stopAnimating()
            },
            failure: { (operation: AFHTTPRequestOperation!,error: NSError!) in
                println("uuuError: " + error.localizedDescription)
                //google timeout
                activityIndicatorView.stopAnimating()
                //self.myNameLabel.text = ":("
                
                var alert = UIAlertController(title: "Alert", message: "Message", preferredStyle: UIAlertControllerStyle.Alert)
                alert.addAction(UIAlertAction(title: "Ok", style: UIAlertActionStyle.Default, handler: nil))
                self.presentViewController(alert, animated: true, completion: nil)
        })*/
    }

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


