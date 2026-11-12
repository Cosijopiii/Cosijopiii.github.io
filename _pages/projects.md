---
layout: page
title: Teaching
permalink: /Teaching/
description: Workshops, talks, and course materials
nav: true
nav_order: 2
---

<div class="teaching-panels">
  <section class="card teaching-panel">
    <div class="card-body">
      <h2>Workshops &amp; Talks</h2>
      <p>Presentations, tutorials, and workshop materials.</p>
      {% assign workshops = site.projects | where: "category", "workshops" | sort: "importance" %}
      {% for project in workshops %}
      <h3><a href="{{ project.url | relative_url }}">{{ project.title }}</a></h3>
      <p>{{ project.description }}</p>
      {% endfor %}
    </div>
  </section>

  <section class="card teaching-panel">
    <div class="card-body">
      <h2>Courses</h2>
      <p>Course materials organized by institution.</p>
      {% assign courses = site.projects | where: "category", "courses" | sort: "importance" %}
      {% for project in courses %}
      <h3><a href="{{ project.url | relative_url }}">{{ project.title }}</a></h3>
      <p>{{ project.description }}</p>
      {% endfor %}
    </div>
  </section>
</div>
