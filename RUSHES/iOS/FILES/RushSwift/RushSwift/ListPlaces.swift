//
//  ListPlaces.swift
//  RushSwift
//
//  Created by David TEDGUI on 2/13/16.
//  Copyright © 2016 David TEDGUI. All rights reserved.
//

struct ListPlaces {
    var places: [String: [Double]] = [
        "Paris": [48.864716, 2.349014],
        "London": [51.508530, -0.076132],
        "Barcelona": [41.390205, 2.154007],
        "Jerusalem": [31.771959, 35.217018],
        "Bogota": [4.624335, -74.063644],
        "Tokyo": [35.652832, 139.839478],
        "Tel Aviv": [32.109333, 34.855499] ]
    
    func returnCities() -> [String] {
        var cities: [String] = []
        
        for (place, _) in places {
            cities.append(place)
        }
        return cities.sort()
    }
}