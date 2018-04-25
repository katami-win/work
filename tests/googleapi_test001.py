#!/usr/bin/env python
# -*- coding: euc-jp -*- 


##
# @file googleapi_test001.py
# @brief 

import array
import json
import gspread
from oauth2client.client import SignedJwtAssertionCredentials


def main():

  doc_id =  '1ispocwhx488T1eO3SIyLAV07oDu1jfJ3M6WdfltNF5Q'

  json_key    = json.load(open('./Seminar Project-6618d04ae42a.json'))
  scope       = ['https://spreadsheets.google.com/feeds']
  #print json_key['client_email']
  credentials = SignedJwtAssertionCredentials(
                  json_key['client_email'], 
                  json_key['private_key'].encode(), 
                  scope)

  gclient = gspread.authorize(credentials)
  gfile   = gclient.open_by_key(doc_id)
  wsheet  = gfile.get_worksheet(0)
  records = wsheet.get_all_records()

  items = ['Date','Time','Temperature','Humidity','Pressure', 'Accelerometer','Illumination','GPS']
 
  #header = records.pop(0)
  #print(header['Header'])
  #print

  #print records
  #print items
  for key in items:
    print(key),
  print
  for record in records:
    for key in items:
      print(record[key]),
    print


if __name__ == '__main__':
  main()
