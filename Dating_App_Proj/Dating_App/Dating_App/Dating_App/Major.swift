//
//  Major.swift
//  Simple
//
//  Created by Clement Chan on 7/27/15.
//  Copyright (c) 2015 Clement Chan. All rights reserved.
//

import Foundation
import UIKit

class Major: UIViewController,UIPickerViewDelegate,UIPickerViewDataSource{
    
    @IBOutlet weak var myPicker: UIPickerView!
    
    var Major = "";
    
    
    @IBAction func UpdateMajor(sender: AnyObject) {
        self.updateMajor();
        loadDestinationVC();
    }
    
    
    override func viewDidLoad() {
        // Do any additional setup after loading the view, typically from a nib.
        myPicker.delegate = self;
        myPicker.dataSource = self;
    }
    
    override func didReceiveMemoryWarning() {
        // Dispose of any resources that can be recreated.
    }
    
    enum PickerComponent:Int{
        case loc = 0
    }
    
    func updateMajor(){
        var sizeComponent = PickerComponent.loc.rawValue
        let size = pickerData[sizeComponent][myPicker.selectedRowInComponent(sizeComponent)]
        self.Major = size;
        register_info.Major = self.Major;
        println(register_info.Major);
    }
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return pickerData.count
    }

    let pickerData = [
        [   "Accounting",
            "Acting",
            "Actuarial Science",
            "Advertising",
            "Aeronautical and Astronautical Engineering",
            "Aeronautical Engineering Technology",
            "Aerospace Financial Analysis",
            "African American Studies",
            "Agricultural Education",
            "Airline Management and Operations",
            "Airport Management and Operations",
            "American Studies",
            "Animal Sciences",
            "Animation",
            "Anthropology",
            "Applied Meteorology and Climatology",
            "Art History",
            "Asian Studies",
            "Atmospheric Science/Meteorology",
            "Audio Engineering Technology",
            "Aviation Management",
            "Biochemistry",
            "Biochemistry (Biology)",
            "Biochemistry (Chemistry)",
            "Biological Engineering - multiple concentrations",
            "Biology",
            "Biology Education",
            "Biomedical Engineering",
            "Brain and Behavioral Sciences",
            "Building Construction Management Technology",
            "Building Information Modeling",
            "Business Management",
            "Cell, Molecular, and Developmental Biology",
            "Chemical Engineering",
            "Chemistry",
            "Civil Engineering",
            "Classical Studies",
            "Communication, General",
            "Comparative Literature",
            "Computer and Information Technology",
            "Computer Engineering",
            "Computer Science",
            "Construction Engineering",
            "Corporate Communication",
            "Creative Writing",
            "Criminal Justice",
            "Developmental and Family Science",
            "Earth/Space Science Education",
            "Ecology, Evolution, and Environmental Sciences",
            "Economics",
            "Effects Technical Direction",
            "Electrical Engineering",
            "Elementary Education",
            "English",
            "English Education",
            "Entomology",
            "Environmental and Ecological Engineering",
            "Environmental and Natural Resources Engineering",
            "Environmental Geosciences",
            "Environmental Health Sciences",
            "Environmental Studies",
            "Family and Consumer Sciences Education",
            "Farm Management",
            "Film and Theatre Production",
            "Film and Video Studies",
            "Finance",
            "Financial Counseling and Planning",
            "Fine Arts",
            "Fisheries and Aquatic Sciences",
            "Food Science",
            "Foods and Nutrition in Business",
            "French",
            "Genetic Biology",
            "Geology and Geophysics",
            "German",
            "Graphic Design",
            "Health Sciences - Preprofessional",
            "Healthcare Construction Management",
            "History",
            "Hospitality and Tourism Management",
            "Human Relations",
            "Industrial Engineering",
            "Interior Design",
            "International Business",
            "Italian Studies",
            "Japanese",
            "Juris Doctor",
            "Journalism",
            "Law",
            "Landscape Architecture",
            "Linguistics",
            "Management",
            "Materials Engineering",
            "Mathematics",
            "MBA",
            "Mechanical Engineering",
            "Medieval and Renaissance Studies",
            "Meteorology",
            "Movement and Sport Sciences",
            "Natural Resources and Environmental Science",
            "Neurobiology and Physiology",
            "Nuclear Engineering",
            "Nursing",
            "Nutrition Science",
            "Pharmaceutical Sciences",
            "Philosophy",
            "Photography",
            "Physics",
            "Planetary Sciences",
            "Political Science",
            "Pre Med",
            "Professional Writing",
            "Public Health",
            "Public Relations and Strategic Communication",
            "Religious Studies",
            "Retail Management",
            "Russian",
            "Sales and Marketing",
            "Social Studies Education",
            "Sociology",
            "Spanish",
            "Statistics",
            "Studio Arts and Technology",
            "Supply Chain Management",
            "Systems Analysis and Design",
            "Theatre Art",
            "Visual Art",
            "Zoology"
    ]
    ]
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return pickerData[component].count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String! {
        return pickerData[component][row]
    }
    
    /*Function to change the color of the fonts in the pickerview*/
    
    func pickerView(pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusingView view: UIView!) -> UIView
    {
        var pickerLabel = UILabel()
        pickerLabel.textColor = UIColor.whiteColor()
        pickerLabel.text = pickerData[component][row]
        pickerLabel.font = UIFont(name: pickerLabel.font.fontName, size: 14)
        //pickerLabel.font = UIFont(name: "System Thin", size: 12) // In this use your custom font
        pickerLabel.textAlignment = NSTextAlignment.Center
        return pickerLabel
    }
    
    
    func loadDestinationVC(){
        self.performSegueWithIdentifier("Beer_Wine", sender: nil)
    }
    
}

