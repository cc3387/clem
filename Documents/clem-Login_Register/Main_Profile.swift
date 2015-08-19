//
//  Main_Profile.swift
//  Dating_App
//
//  Created by Clement Chan on 7/19/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import UIKit

class Main_Profile: UIViewController {
    
    var numberToDisplay = 0;
    
    @IBOutlet weak var numbers: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        numbers.text = "Welcome to the profile page!"
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

