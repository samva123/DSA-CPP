# we are using nodejs as base image (its a basic source to run application)
FROM node:22

#we are creating a directory inside the container
WORKDIR /app


#copying the files (package.json) to current directory/app
COPY package*.json .

# install the dependency
RUN npm install

COPY . . 

#PROVIDING ENV VARIABLES
ENV PORT=4000


EXPOSE 4000


CMD ["npm", "start"]