                            (nsip, vip)
                            
              Client--------LB(Appflow commands) ---- vServer
                              ||
                               ADM Agent(Doing analytics for data received from LB e.g. Transaction data, metrics data, Auditlogs)
                               (nsulfd---> shred memore limit is 128MB-----> lstreamd consumer)
                
                
                
                
                
               
 nsulfd- receives connection from the LB and writes the data into shared memory
 lstreadm - consumes data from the SH memory region.
                
 Project- Lb is sending data e.g. Transaction data, metrics data, Auditlogs to ADM agent for the analytics purpose so for transation(Data is in the form of templates)
   data if we add some fields to an existing template or we add new tempate then we have to certain changes on the ADM agent side for the analytics of the new data.
     Generally we do the below changes
     1. We edit the schemaFile for the new field or new template and then we generate header file
     2. get_protocol_id will help the template added or edited falls on which traffics
     3. we create the obj of that class and fill the fields value by case mapping 
     4. we write the data into avrofiles in some format e.g. rec_type and all their fields.
     5. We send that avro file to the end point(CAS Citrix analyics solutions).
       
       
 Multithreading - 
       
       
       
  Autoscale Group Id Chnage -
       
                  Redis
                  ||
                  ADM Agent

       
       
 Project-
       Automated the analytics data pipeline(Automation of LogProxy code).
