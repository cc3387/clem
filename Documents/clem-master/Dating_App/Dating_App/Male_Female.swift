//
//  Male_Female.swift
//  Simple
//
//  Created by Clement Chan on 7/26/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class Male_Female: UIViewController{
    
    override func viewDidLoad() {
    
        var leftSwipe = UISwipeGestureRecognizer(target: self, action: ("handleSwipes:"))
        var rightSwipe = UISwipeGestureRecognizer(target: self, action: ("handleSwipes:"))
        
        leftSwipe.direction = .Left
        rightSwipe.direction = .Right
        
        view.addGestureRecognizer(leftSwipe)
        view.addGestureRecognizer(rightSwipe)
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    func handleSwipes(sender:UISwipeGestureRecognizer){
        
        if(sender.direction == .Right){
        register_info.Gender = "Female"
        loadDestinationVC()
        println(register_info.Gender)
        }
        else if(sender.direction == .Left){
        register_info.Gender = "Male"
        loadDestinationVC()
        println(register_info.Gender)
        }
    }

    func loadDestinationVC(){
        self.performSegueWithIdentifier("Education", sender: nil)
    }
    
}
