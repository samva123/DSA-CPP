"use client"
import axios from 'axios';
import { useRouter } from 'next/navigation';
import React, { useState } from 'react';

const Page = () => {
  const [name , setName] = useState('');
  const [email , setEmail] = useState('');
  const [password , setPassword] = useState('');
  const router = useRouter();

  const submitHandler = async (e) => {
    e.preventDefault();
    let payload = {
      name,
      email,
      password
    }
    let res = await axios.post("http://localhost:5000/auth/signup" , payload);
    if(res.status == 201){
      router.push('/login');
    }
    
  }


  return (
    <div className="min-h-screen flex items-center justify-center bg-gradient-to-br from-blue-900 via-black to-blue-950">
      <div className="bg-black/40 p-8 rounded-2xl shadow-lg w-full max-w-md">
        <h1 className="text-3xl font-bold text-yellow-400 text-center mb-6">Sign Up</h1>
        <form onSubmit={submitHandler} className="space-y-4">
          <div>
            <label htmlFor="name" className="block text-gray-300 mb-1">Name:</label>
            <input 
              onChange={(e) => setName(e.target.value)} 
              id="name" 
              placeholder="Enter your name" 
              className="w-full p-2 rounded-lg bg-gray-800 text-white placeholder-gray-600 focus:outline-none focus:ring-2 focus:ring-yellow-400"
            />
          </div>

          <div>
            <label htmlFor="email" className="block text-gray-300 mb-1">Email:</label>
            <input 
              onChange={(e) => setEmail(e.target.value)} 
              id="email" 
              type="email" 
              placeholder="Enter your email" 
              className="w-full p-2 rounded-lg bg-gray-800 text-white placeholder-gray-600 focus:outline-none focus:ring-2 focus:ring-yellow-400"
            />
          </div>

          <div>
            <label htmlFor="password" className="block text-gray-300 mb-1">Password:</label>
            <input 
              onChange={(e) => setPassword(e.target.value)} 
              id="password" 
              type="password" 
              placeholder="Enter your password" 
              className="w-full p-2 rounded-lg bg-gray-800 text-white placeholder-gray-600 focus:outline-none focus:ring-2 focus:ring-yellow-400"
            />
          </div>

          <button 
            type="submit" 
            className="w-full py-2 mt-4 bg-yellow-400 text-black font-bold rounded-lg shadow-lg hover:shadow-yellow-500/70 hover:bg-yellow-300 transition-all"
          >
            Sign Up
          </button>
        </form>
      </div>
    </div>
  );
};

export default Page;
