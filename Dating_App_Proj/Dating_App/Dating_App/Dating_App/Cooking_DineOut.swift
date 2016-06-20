//
//  Cooking_DineOut.swift
//  Simple
//
//  Created by Clement Chan on 9/30/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation

import UIKit

class Cooking_DineOut: UIViewController{
    
    override func viewDidLoad() {
        
        var leftSwipe = UISwipeGestureRecognizer(target: self, action: ("CookingDineoutSwipe:"))
        var rightSwipe = UISwipeGestureRecognizer(target: self, action: ("CookingDineoutSwipe:"))
        
        leftSwipe.direction = .Left
        rightSwipe.direction = .Right
        
        view.addGestureRecognizer(leftSwipe)
        view.addGestureRecognizer(rightSwipe)
        
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    func CookingDineoutSwipe(sender:UISwipeGestureRecognizer){
        
        if(sender.direction == .Right){
            register_info.Cooking_Dineout = "Cooking_Home"
            loadDestinationVC()
            println(register_info.Cooking_Dineout)
        }
        else if(sender.direction == .Left){
            register_info.Cooking_Dineout = "Dine_Out"
            loadDestinationVC()
            println(register_info.Cooking_Dineout)
        }
    }

    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Choose_Profile_Pic", sender: nil)
    }
    
}