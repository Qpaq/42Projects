//
//  ListPlaces.swift
//  RushSwift
//
//  Created by David TEDGUI on 2/13/16.
//  Copyright © 2016 David TEDGUI. All rights reserved.
//

import MapKit

struct PlaceDetails {
    let subtitle: String
    let latitude: Double
    let longitude: Double
	var zoom: Double = 0.3
    
	init(subtitle: String, latitude: Double, longitude: Double, zoom: Double) {
        self.subtitle = subtitle
        self.latitude = latitude
        self.longitude = longitude
		self.zoom = zoom
    }
}

struct ListPlaces {
    var places: [String: PlaceDetails] = [
		"Paris": PlaceDetails(subtitle: "The city of love", latitude: 48.864716, longitude: 2.349014, zoom: 0.3),
        "London": PlaceDetails(subtitle: "The city of love", latitude: 51.508530, longitude: -0.076132, zoom: 0.3),
        "Barcelona": PlaceDetails(subtitle: "The city of love", latitude: 41.390205, longitude: 2.154007, zoom: 0.3),
        "Jerusalem": PlaceDetails(subtitle: "The city of love", latitude: 31.771959, longitude: 35.217018, zoom: 0.3),
        "Bogota": PlaceDetails(subtitle: "The city of love", latitude: 4.624335, longitude: -74.063644, zoom: 0.3),
        "Tokyo": PlaceDetails(subtitle: "The city of love", latitude: 35.652832, longitude: 139.839478, zoom: 0.3),
        "Tel Aviv": PlaceDetails(subtitle: "The city of love", latitude: 32.109333, longitude: 34.855499, zoom: 0.3),
        "42": PlaceDetails(subtitle: "Born to Code", latitude: 48.896684, longitude: 2.318376, zoom: 0.02) ]
    
    
    func returnCities() -> [String] {
        var cities: [String] = []
        
        for (place, _) in places {
            cities.append(place)
        }
        return cities.sort()
    }
    
    func returnPlaceInfo(placeName: String) -> PlaceDetails {
        return places[placeName]!
    }
    
    func returnPlaceCoordinates(placeName: String) -> MKCoordinateRegion {
        let placeInfos = self.places[placeName]!
        
        let placeLocationCoordinate = CLLocationCoordinate2D(latitude: placeInfos.latitude, longitude: placeInfos.longitude)
		let placeCoordinateRegion = MKCoordinateRegion(center: placeLocationCoordinate, span: MKCoordinateSpan(latitudeDelta: placeInfos.zoom, longitudeDelta: placeInfos.zoom))
		
        return placeCoordinateRegion
    }

}