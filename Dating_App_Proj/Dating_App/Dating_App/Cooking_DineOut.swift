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
    
    
    
    @IBAction func Cooking_Home(sender: AnyObject) {
        
        register_info.Cooking_Dineout = "Cooking_Home";
        
        loadDestinationVC();
        
        println(register_info.Cooking_Dineout);
    }
    
    
    @IBAction func Dine_Out(sender: AnyObject) {
    
        register_info.Cooking_Dineout = "Dine_Out";
        
        loadDestinationVC();
    
        println(register_info.Cooking_Dineout);
    }
    
    override func viewDidLoad() {
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Summary_Send", sender: nil)
    }
    
}