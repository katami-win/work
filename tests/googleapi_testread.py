#!/usr/bin/env python
# -*- coding: euc-jp -*- 


##
# @file googleapi_testread.py
# @brief 

import os
import array
import json
import gspread
#from oauth2client.client import SignedJwtAssertionCredentials
from oauth2client.service_account import ServiceAccountCredentials

def main():

  #doc_id =  '1zds4WRV3CQzSov9ATJrxs454H9UAYwSEquaqH22YBbM'
  #doc_id =  '1bZTdob0RF_Vq1xxyMNN8MmwSk19wW629yS21XJ2M4YA'
  doc_id =  '12m8fQQBRNKPEzKOjilJldZKlam7jf5BlCp7ZazNkVvU'
  #json_key    = json.load(open('newproject-1-6f8d8d9e6dc4.json'))
  #json_key    = json.load(open('shizu-241851f95630.json'))
  json_path = 'iot-summer-c1652295662e.json'
  print(json_path)

  scope       = ['https://spreadsheets.google.com/feeds']
  #print json_key['client_email']
  #credentials = SignedJwtAssertionCredentials(
  #                json_key['client_email'], 
  #                json_key['private_key'].encode(), 
  #                scope)
  credentials =  ServiceAccountCredentials.from_json_keyfile_name(
                  json_path,scope)

  #print doc_id
  gclient = gspread.authorize(credentials)
  gfile   = gclient.open_by_key(doc_id)
  wsheet  = gfile.get_worksheet(0)

  records = wsheet.get_all_records()

  print records 


if __name__ == '__main__':
  main()
